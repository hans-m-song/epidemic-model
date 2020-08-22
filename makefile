CXX=g++
CXXFLAGS = -Wall -pedantic -g
OBJ = debug.o epidemic.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o epidemic $(OBJ)

clean:
	rm -f *.o
	rm -f epidemic
