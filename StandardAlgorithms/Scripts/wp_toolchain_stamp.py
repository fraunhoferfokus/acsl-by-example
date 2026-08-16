#!/usr/bin/env python3
"""Update a content-stable signature for the WP verification toolchain."""

from __future__ import annotations

import argparse
import fcntl
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import tempfile


def command_argv(command: str) -> list[str]:
    argv = shlex.split(command)
    if not argv:
        raise ValueError("empty command")
    return argv


def run(command: list[str]) -> str:
    completed = subprocess.run(
        command,
        check=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    return completed.stdout.strip()


def executable_details(command: list[str]) -> dict[str, object]:
    executable = shutil.which(command[0])
    if executable is None:
        return {"command": command, "resolved": None}

    resolved = Path(executable).resolve()
    stat = resolved.stat()
    return {
        "command": command,
        "resolved": str(resolved),
        "size": stat.st_size,
        "mtime_ns": stat.st_mtime_ns,
    }


def detected_prover_commands(output: str) -> list[str]:
    commands = []
    for line in output.splitlines():
        if "Prover " not in line:
            continue
        matches = re.findall(r"\(([^()]*)\)", line)
        if matches:
            commands.append(matches[0])
    return sorted(set(commands))


def write_if_changed(output: Path, data: bytes) -> None:
    output.parent.mkdir(parents=True, exist_ok=True)
    lock_path = output.with_name(f".{output.name}.lock")
    with lock_path.open("w") as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        if output.is_file() and output.read_bytes() == data:
            return

        fd, temporary_name = tempfile.mkstemp(
            prefix=f".{output.name}.",
            dir=output.parent,
        )
        temporary = Path(temporary_name)
        try:
            with os.fdopen(fd, "wb") as stream:
                stream.write(data)
            os.replace(temporary, output)
        finally:
            temporary.unlink(missing_ok=True)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--frama-c", required=True)
    parser.add_argument("--compiler", required=True)
    parser.add_argument("--prover", action="append", default=[])
    args = parser.parse_args()

    frama_c = command_argv(args.frama_c)
    compiler = command_argv(args.compiler)
    prover_flags = [
        item
        for prover in args.prover
        for item in ("-wp-prover", prover)
    ]
    prover_output = run(frama_c + prover_flags + ["-wp-list-provers"])

    signature = {
        "schema": 1,
        "frama_c": {
            **executable_details(frama_c),
            "version": run(frama_c + ["-version"]),
        },
        "compiler": {
            **executable_details(compiler),
            "version": run(compiler + ["--version"]),
        },
        "configured_provers": args.prover,
        "detected_provers": prover_output,
        "prover_executables": [
            executable_details([command])
            for command in detected_prover_commands(prover_output)
        ],
    }
    serialized = (json.dumps(signature, indent=2, sort_keys=True) + "\n").encode()
    write_if_changed(args.output, serialized)


if __name__ == "__main__":
    main()
