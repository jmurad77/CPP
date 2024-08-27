#-D(NAME) this is how you define a #define in the make file
CPP=g++ -std=c++17

OUT: main.o
	$(CPP) main.o -o OUT

# For template classes they need to be included in the client code and connot be built as ConcurrentQueue.o
main.o: main.cpp ConcurrentQueue.h ConcurrentQueue.cpp
	$(CPP) -c main.cpp

clean:
	rm *.o OUT
