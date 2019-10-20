DEPS = atmega328p
NAME := cpu_assets
DEPENDENCIES := $(DEPS:%=lib%.so)
LIB_LIST := $(DEPS:%=-l%)
SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJECTS := $(SOURCES:%.cpp=%.o)
MAKEFILES = $(OBJECTS:%.o=%.mk)
LIBS := $(addprefix -l, $(DEPS))
OUTPUT := $(NAME:%=lib%.so)
LIBSDIR := -L$(LIB_DIR)
TARGET := $(LIB_DIR)/$(OUTPUT)

.PHONY: build clean force

build: $(TARGET)

clean: $(DEPS:%=clean_%)
	$(RMCMD) $(LIB_DIR)/libcpu_assets.so
	$(RMCMD) *.o
	$(RMCMD) *.mk
	$(RMCMD) *.gcno
	$(RMCMD) *.gcda

clean_% : force
	cd $(@:clean_%=%); $(MAKE) $(MAKECMDGOALS)

$(DEPENDENCIES) :
	cd $(@:lib%.so=%); $(MAKE) $(MAKECMDGOALS)

$(TARGET) : $(OBJECTS) $(DEPENDENCIES)
	$(COMPILE_LIB) -o $@ $(OBJECTS) $(LIBSDIR) $(LIBS)

$(OBJECTS) : %.o : %.cpp %.mk
	$(COMPILE_OBJECT) -o $@ $<

%.mk : %.cpp
	$(GET_INCLUDES) -o $@ $<