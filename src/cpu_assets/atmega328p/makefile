SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJECTS := $(SOURCES:%.cpp=../%.o)

.PHONY : build clean
build : $(OBJECTS)
clean :
	$(RMCMD) $(OBJECTS)
	$(RMCMD) *.mk
	$(RMCMD) *.gcno
	$(RMCMD) *.gcda

$(OBJECTS) : ../%.o : %.cpp %.mk
	$(COMPILE_OBJECT) -o $@ $<

%.mk : %.cpp
	$(GET_INCLUDES) -o $@ $<