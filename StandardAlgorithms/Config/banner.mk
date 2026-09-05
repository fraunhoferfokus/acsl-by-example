
# -----------------------------------------------------------------------------
# banner.mk --- the one place a directory heading is spelled.
#
# Included both by dispatch.mk (top level) and by internal.mk (Stack/), so the
# two recursion loops cannot drift apart. The guard keeps make from warning
# about a duplicate definition when both paths lead here in one invocation.
#
# The convention: a blank line always *precedes* a heading, and nothing follows
# it. Every dispatched target therefore frames its subdirectories identically,
# and no *-local recipe contributes spacing of its own. Leading rather than
# trailing is what makes the nested case come out right: Stack/ is an internal
# directory and a leaf at once, so its own output is followed directly by its
# subdirectories' headings, which bring their own separator with them.
# -----------------------------------------------------------------------------

ifndef BANNER_MK_INCLUDED
BANNER_MK_INCLUDED := 1

define _dir_heading
printf '\n -- %s  %s -- \n' "$(1)" "$(2)"
endef

endif
