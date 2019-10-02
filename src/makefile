CURRENT_DIR := $(shell pwd)
SUBDIRS := $(filter %/, $(wildcard $(CURRENT_DIR)/*/))
CLEAN_SUBDIRS := $(addsuffix _clean, $(SUBDIRS))
BUILD_SUBDIRS := $(addsuffix _build, $(SUBDIRS))

.PHONY: $(LIB_LIST) clean build

build: $(BUILD_SUBDIRS)
clean: $(CLEAN_SUBDIRS)

run $(LIB_LIST):
	cd $@; $(MAKE) $(MAKECMDGOALS)

%_clean %_build: %
	cd $<; $(MAKE) $(MAKECMDGOALS)
