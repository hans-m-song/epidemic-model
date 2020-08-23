CXX=g++
CXXFLAGS = -Wall -pedantic -g -std=c++11
OBJ = agent.o debug.o epidemic.o main.o position.o util.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: main

new: clean main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o epidemic $(OBJ)

clean:
	rm -f *.o
	rm -f epidemic
