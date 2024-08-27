#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: main.o OUT

OUT: main.o
	$(CPP) main.o -o OUT

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
