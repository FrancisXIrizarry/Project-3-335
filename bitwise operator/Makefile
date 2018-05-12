SRCS       := main.cpp small_set.cpp
OBJS       := $(patsubst %.cpp, %.o, $(SRCS))
EXEC       := setops 
CXX        := /usr/bin/g++
CXXFLAGS     += -Wall -g

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS)  -o $(EXEC)  $(OBJS)

.PHONY: clean cleanall
cleanall: clean
	$(RM) $(EXEC)

clean:
	$(RM) $(OBJS)

main.o: small_set.h 
small_set.o: small_set.h

