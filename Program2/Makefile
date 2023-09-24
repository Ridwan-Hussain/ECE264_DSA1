BIN := SingleFile
SRC := $(wildcard *.cpp)
DEP := $(SRC:.cpp=.d)

CXX := g++
CXXFLAGS := -g -Wall -Wextra -Wpedantic


.PHONY: all
all: $(BIN)


-include $(DEP)


.PHONY: clean
clean:
	@rm -rvf *.d *.o $(BIN)


$(BIN): SingleFile.o
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MM $< -MF $*.d
	$(CXX) $(CXXFLAGS) -c $<
