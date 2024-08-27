#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: LinkList.o BitMainIp.o Sorting.o Tree.o Utilities.o StlDataStructures.o Cpp_Advanced.o main.o OUT

OUT: main.o
	$(CPP) main.o LinkList.o BitMainIp.o Sorting.o Tree.o Utilities.o StlDataStructures.o Cpp_Advanced.o -o OUT

Cpp_Advanced.o: Cpp_Advanced.cpp Cpp_Advanced.h
	$(CPP) -c Cpp_Advanced.cpp

StlDataStructures.o: StlDataStructures.cpp StlDataStructures.h
	$(CPP) -c StlDataStructures.cpp

BitMainIp.o: BitMainIp.cpp BitMainIp.h
	$(CPP) -c BitMainIp.cpp

Sorting.o: Sorting.cpp Sorting.h
	$(CPP) -c Sorting.cpp

Tree.o: Tree.cpp Tree.h
	$(CPP) -c Tree.cpp

Utilities.o: Utilities.cpp Utilities.h
	$(CPP) -c Utilities.cpp

LinkList.o: LinkList.cpp LinkList.h
	$(CPP) -c LinkList.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
