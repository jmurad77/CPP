#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

all: Threading_Async_Lambdas.o main.o OUT

OUT: main.o
	$(CPP) main.o Threading_Async_Lambdas.o -o OUT

Threading_Async_Lambdas.o: Threading_Async_Lambdas.cpp Threading_Async_Lambdas.h
	$(CPP) -c Threading_Async_Lambdas.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
