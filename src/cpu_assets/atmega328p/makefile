NAME := atmega328p
OUTPUT := $(addprefix lib, $(addsuffix .so, $(NAME)))
SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJECTS := $(SOURCES:%.cpp=%.o)
MAKEFILES = $(OBJECTS:%.o=%.mk)

.PHONY : build clean
build : $(LIB_DIR)/$(OUTPUT)
clean :
	$(RMCMD) $(LIB_DIR)/$(OUTPUT)
	$(RMCMD) *.o
	$(RMCMD) *.mk
	$(RMCMD) *.gcno
	$(RMCMD) *.gcda

$(LIB_DIR)/$(OUTPUT) : $(OBJECTS)
	$(COMPILE_LIB) -o $@ $^

$(OBJECTS) : %.o : %.cpp %.mk
	$(COMPILE_OBJECT) -o $@ $<

%.mk : %.cpp
	$(GET_INCLUDES) -o $@ $<