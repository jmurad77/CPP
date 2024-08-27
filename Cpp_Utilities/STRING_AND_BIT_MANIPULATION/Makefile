#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: StringAndBitManip.o main.o OUT

OUT: main.o
	$(CPP) main.o StringAndBitManip.o -o OUT

StringAndBitManip.o: StringAndBitManip.cpp StringAndBitManip.h
	$(CPP) -c StringAndBitManip.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
