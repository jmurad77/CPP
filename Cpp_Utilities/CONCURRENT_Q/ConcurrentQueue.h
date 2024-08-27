#ifndef CONCURRENT_QUEUE_H
#define CONCURRENT_QUEUE_H

#include <deque>
#include <mutex>
#include <thread>
#include <stdint.h>
#include <condition_variable>
#include <sstream>

using namespace std;
using namespace chrono_literals;

template <class T>
class Concurrent_Queue
{
private:
    std::mutex myMutex;
    std::condition_variable myCv;
    std::unique_ptr<deque<T>> myQueue;
    uint32_t myMaxSize;

public:
    Concurrent_Queue()
    {
        myQueue = std::make_unique<deque<T>>();
        myMaxSize = 0;

    }

    Concurrent_Queue(uint32_t size)
    {
        myQueue = std::make_unique<deque<T>>(size);
        myMaxSize = 0;
    }

    void PushBack(T data)
    {
        std::unique_lock<std::mutex> lock(myMutex);
        myQueue->push_back(data);
        myCv.notify_one();
    }

    void PushFront(T data)
    {
        std::unique_lock<std::mutex> lock(myMutex);
        myQueue->push_front(data);
        myCv.notify_one();
    }

    pair<bool, T> Pop(uint32_t wait)
    {
        T ret;
        bool timeout = true;
        
        std::unique_lock<std::mutex> lock(myMutex);
        
        if (myQueue->empty())
        {
            if (cv_status::timeout == myCv.wait_for(lock,1ms * wait))
            {
                return make_pair(timeout, ret);
            }
        }
        
        if(!myQueue->empty())
        {
            timeout = false;
            ret = myQueue->front();
		    myQueue->pop_front();
        }

        return make_pair(timeout, ret);
    }

    uint32_t GetSize()
    {
        std::unique_lock<std::mutex> lock(myMutex);
        return (uint32_t)myQueue->size();
    }

    uint32_t GetMaxSize()
    {
        std::unique_lock<std::mutex> lock(myMutex);
        return (uint32_t)myQueue->max_size();
    }

    bool IsEmpty()
    {
        std::unique_lock<std::mutex> lock(myMutex);
        return myQueue->size() == 0;
    }

    void ClearContents()
    {
        std::unique_lock<std::mutex> lock(myMutex);
        myQueue->clear();
    }

    T PeakFront()
    {
        T ret;
        std::unique_lock<std::mutex> lock(myMutex);
        if (myQueue->size() != 0)
        {
            ret = myQueue->front();
        }

        return ret;
    }

    T PeakBack()
    {
        T ret;
        std::unique_lock<std::mutex> lock(myMutex);
        if (myQueue->size() != 0)
        {
            ret = myQueue->back();
        }

        return ret;
    }
};
#endif