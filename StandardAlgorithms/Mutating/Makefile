
# Makefile (directory-local configuration)

TOP_DIR     ?= $(abspath ..)
CONFIG_DIR  := ../Config

include $(CONFIG_DIR)/examples.mk

# disable -warn-unsigned-overflow
random_number.wp random_number.wplog random_number.wp/proof-results.json: \
  WP_RTE_FLAGS = -no-warn-unsigned-overflow -warn-unsigned-downcast
