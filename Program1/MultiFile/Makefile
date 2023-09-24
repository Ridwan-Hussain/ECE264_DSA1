# Constant definition
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

foobar: main.o filefunctions.o vectorfunctions.o
	$(CXX) $(CXXFLAGS) -o foobar filefunctions.o vectorfunctions.o

main.o: main.cpp foobar.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

filefunctions.o: filefunctions.cpp foobar.hpp
	$(CXX) $(CXXFLAGS) -c filefunctions.cpp

vectorfunctions.o: vectorfunctions.cpp foobar.hpp
	$(CXX) $(CXXFLAGS) -c vectorfunctions.cpp

.PHONY: clean
clean:
	rm -f *.o
