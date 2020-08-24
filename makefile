CXX=g++
CXXFLAGS = -Wall -pedantic -g -std=c++14
OBJ = util.o debug.o coordinate.o agent.o coordinate_map.o epidemic.o main.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: main

new: clean main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o epidemic $(OBJ)

clean:
	rm -f *.o
	rm -f epidemic
