
# Makefile (directory-local configuration)

TOP_DIR     ?= $(abspath ..)
CONFIG_DIR  := $(TOP_DIR)/Config

include $(CONFIG_DIR)/examples.mk

# disable -warn-unsigned-overflow
random_number.wp random_number.wplog: \
  WP_RTE_FLAGS = -no-warn-unsigned-overflow -warn-unsigned-downcast

