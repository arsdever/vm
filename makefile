export BASE_DIR := $(shell pwd)
export SRC_DIR := $(BASE_DIR)/src
export OUT_DIR := $(BASE_DIR)/build
export LIB_DIR := $(OUT_DIR)/lib
export TEST_DIR := $(BASE_DIR)/test
export TEST_BUILD_DIR := $(TEST_DIR)/build
export INCLUDES := $(SRC_DIR)
export LIB_LIST := cpu_assets
export LIBS = $(addprefix -l, $(LIB_LIST))
export RMCMD := rm -fr
export CPP := g++
export CPPFLAGS := -g -std=c++14 -lgcov -fprofile-arcs -ftest-coverage -fPIC -DDEBUGGING

.PHONY : build rebuild run clean test create_folders

$(LIB_LIST) build run: create_folders
	cd $(SRC_DIR); $(MAKE) $(MAKECMDGOALS)

clean:
	cd $(SRC_DIR); $(MAKE) $(MAKECMDGOALS)
	cd $(TEST_DIR); $(MAKE) $(MAKECMDGOALS)

test:
	$(MAKE) $(LIB_LIST)
	cd $(TEST_DIR); $(MAKE) $(MAKECMDGOALS)

rebuild:
	$(MAKE) clean
	$(MAKE) build

create_folders:
	mkdir -p $(OUT_DIR)
	mkdir -p $(LIB_DIR)
	mkdir -p $(TEST_BUILD_DIR)