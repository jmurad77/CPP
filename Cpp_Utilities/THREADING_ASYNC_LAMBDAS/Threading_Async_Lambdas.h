#ifndef THREADING_ASYNC_LAMBDAS_H
#define THREADING_ASYNC_LAMBDAS_H

using namespace std;

#include <iostream>
#include <thread>
#include <mutex>
#include <stdint.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <memory>
#include <future>
#include <functional>
#include <atomic>

class LambThreads
{
private:
    thread myLocalThread;
    uint32_t myInternalCounter;

public: 
    LambThreads();
    void Stop();
    ~LambThreads();
};

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> myStartTimepoint;
    std::string myName;
public:
    Timer(std::string name)
    {
        myName = name;
        myStartTimepoint = std::chrono::high_resolution_clock::now();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(myStartTimepoint).time_since_epoch();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch();

        auto duration = end - start;
        auto ms = duration * 0.001;
        std::cout << "Process: " << myName << ", Duration: " << duration.count() << "us, " << ms.count() << "ms\n";
    }

    ~Timer()
    {
        Stop();
    }
};

class Entity
{
private:
    uint32_t myWord;
    float myTemp;

public:
    
    Entity()
       : myWord(0), myTemp(0.0f)
    {}

    Entity(uint32_t word, float temp)
       : myWord(word), myTemp(temp)
    {}

    // Simple example for a copy constructor
    Entity(const Entity& obj)
        : myWord(obj.myWord), myTemp(obj.myTemp)
    {
        std:cout << "I HAVE BEEN COPIED\n";
    }
};

void Test_Performance_Vector();

enum class Domain
{
    Width,
    Temperature
};

template<Domain DOMAIN, typename TYPE>
struct StrongType
{
    TYPE m_value;

    StrongType operator+=(const StrongType& other)
    {
        m_value += other;
    }
};

#endif