.PHONY: build clean test

test: $(TEST_BUILD_DIR)/test
	LD_LIBRARY_PATH=$(LIB_DIR) $(TEST_BUILD_DIR)/test

$(TEST_BUILD_DIR)/test: test_6502.cpp
	mkdir -p $(TEST_BUILD_DIR)
	g++ $^ -o $(TEST_BUILD_DIR)/test $(INCLUDES) -L$(LIB_DIR) $(LIBS) -ldl $(CPPFLAGS) -lcpu_assets

clean:
	$(RMCMD) $(TEST_BUILD_DIR)
	$(RMCMD) *.gcno
	$(RMCMD) *.gcda

.PRECIOUS: %.o