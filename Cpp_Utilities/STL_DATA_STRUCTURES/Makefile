#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: StlDataStructures.o main.o OUT

OUT: main.o
	$(CPP) main.o StlDataStructures.o -o OUT

StlDataStructures.o: StlDataStructures.cpp StlDataStructures.h
	$(CPP) -c StlDataStructures.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
