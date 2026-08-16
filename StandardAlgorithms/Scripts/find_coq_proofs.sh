#!/bin/sh
# Compatibility entry point for the JSON-based Coq proof extractor.

exec python3 "$(dirname "$0")/find_coq_proofs.py" "$@"
