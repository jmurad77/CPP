#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: BitMainIp.o main.o OUT

OUT: main.o
	$(CPP) main.o BitMainIp.o -o OUT

BitMainIp.o: BitMainIp.cpp BitMainIp.h
	$(CPP) -c BitMainIp.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
