#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: RegexUtilities.o main.o OUT

OUT: main.o
	$(CPP) main.o RegexUtilities.o -o OUT

RegexUtilities.o: RegexUtilities.cpp RegexUtilities.h
	$(CPP) -c RegexUtilities.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
