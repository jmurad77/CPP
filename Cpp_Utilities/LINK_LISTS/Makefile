#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: LinkList.o main.o OUT

OUT: main.o
	$(CPP) main.o LinkList.o -o OUT

LinkList.o: LinkList.cpp LinkList.h
	$(CPP) -c LinkList.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
