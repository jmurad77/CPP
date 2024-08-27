#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: Sorting.o main.o OUT

OUT: main.o
	$(CPP) main.o Sorting.o -o OUT

Sorting.o: Sorting.cpp Sorting.h
	$(CPP) -c Sorting.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
