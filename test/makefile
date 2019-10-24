TESTCASES = test_6502 test_atmega328p
TESTCASE_FILES = $(TESTCASES:%=$(TEST_BUILD_DIR)/%)

.PHONY: build clean test_all $(TESTCASES)

build : $(TESTCASE_FILES)

test : test_all

test_all : $(TESTS:%=test_%)

$(TESTCASES) :
	cd $(TEST_DIR); LD_LIBRARY_PATH=$(LIB_DIR) $(@:%=$(TEST_BUILD_DIR)/%); cd -

$(TESTCASE_FILES) : $(TEST_BUILD_DIR)/% : %.cpp
	mkdir -p $(TEST_BUILD_DIR)
	$(COMPILE_APP) -o $@ $^ -lcpu_assets

clean:
	$(RMCMD) $(TEST_BUILD_DIR)
	$(RMCMD) *.gcno
	$(RMCMD) *.gcda
