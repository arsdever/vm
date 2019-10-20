DEPS = 6502 atmega328p
NAME := cpu_assets
LIB_LIST := $(DEPS:%=-l%)
SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJECTS := $(SOURCES:%.cpp=%.o)
EXTERNAL_SOURCES = $(foreach dep, $(DEPS), $(notdir $(wildcard $(dep)/*.cpp)))
EXTERNAL_OBJECTS = $(EXTERNAL_SOURCES:%.cpp=%.o)
MAKEFILES = $(OBJECTS:%.o=%.mk)
OUTPUT := $(NAME:%=lib%.so)
LIBSDIR := -L$(LIB_DIR)
TARGET := $(LIB_DIR)/$(OUTPUT)

.PHONY: build clean force $(DEPS)

build: $(TARGET)

clean: $(DEPS:%=clean_%)
	$(RMCMD) $(LIB_DIR)/libcpu_assets.so
	$(RMCMD) *.o
	$(RMCMD) *.mk
	$(RMCMD) *.gcno
	$(RMCMD) *.gcda

clean_% : force
	cd $(@:clean_%=%); $(MAKE) $(MAKECMDGOALS)

$(DEPS) :
	cd $@; $(MAKE) $(MAKECMDGOALS)

$(TARGET) : $(OBJECTS) $(DEPS)
	$(COMPILE_LIB) -o $@ $(OBJECTS) $(EXTERNAL_OBJECTS)

$(OBJECTS) : %.o : %.cpp %.mk
	$(COMPILE_OBJECT) -o $@ $<

%.mk : %.cpp
	$(GET_INCLUDES) -o $@ $<