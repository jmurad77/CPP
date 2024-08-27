#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: FileSystem.o main.o OUT

OUT: main.o
	$(CPP) main.o FileSystem.o -o OUT

FileSystem.o: FileSystem.cpp FileSystem.h
	$(CPP) -c FileSystem.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
