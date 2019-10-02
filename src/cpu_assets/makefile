SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJECTS := $(SOURCES:%.cpp=%.o)
MAKEFILES = $(OBJECTS:%.o=%.mk)

.PHONY: cpu_assets build run clean makefiles

build: $(LIB_DIR)/libcpu_assets.so

clean:
	$(RMCMD) $(LIB_DIR)/libcpu_assets.so

$(LIB_DIR)/libcpu_assets.so: $(OBJECTS)
	$(CPP) -o $@ --shared $(OBJECTS) $(CPPFLAGS)

%.o:
	$(CPP) -c -o $@ $(CPPFLAGS) $< -fPIC

%.mk: %.cpp
	$(CPP) -M -o $@ $(CPPFLAGS) $<
	
.PRECIOUS: %.o

include $(MAKEFILES)