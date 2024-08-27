#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: TcpSocket.o main.o OUT

OUT: main.o
	$(CPP) main.o TcpSocket.o -o OUT

TcpSocket.o: TcpSocket.cpp TcpSocket.h
	$(CPP) -c TcpSocket.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
