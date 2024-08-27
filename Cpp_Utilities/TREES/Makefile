#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: Tree.o main.o OUT

OUT: main.o
	$(CPP) main.o Tree.o -o OUT

Tree.o: Tree.cpp Tree.h
	$(CPP) -c Tree.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
