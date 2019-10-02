.PHONY: build clean test

test: $(TEST_BUILD_DIR)/test
	LD_LIBRARY_PATH=$(LIB_DIR) $(TEST_BUILD_DIR)/test

$(TEST_BUILD_DIR)/test: *.cpp *.h
	mkdir -p $(TEST_BUILD_DIR)
	g++ *.cpp -o $(TEST_BUILD_DIR)/test -I$(INCLUDES) -L$(LIB_DIR) $(LIBS) -ldl $(CPPFLAGS)

.PRECIOUS: %.o