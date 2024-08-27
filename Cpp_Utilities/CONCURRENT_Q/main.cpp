#include <iostream>
#include "ConcurrentQueue.h"

int main()
{
    Concurrent_Queue<int> threadSafeQueue;
    printf("<><><><> INIT QUEUE MAX SIZE: %u <><><><>\n", threadSafeQueue.GetMaxSize());


    threadSafeQueue.PushBack(10);
    threadSafeQueue.PushBack(20);
    threadSafeQueue.PushBack(30);
    threadSafeQueue.PushBack(40);
    printf("<><><><> QUEUE Peak Back: %u <><><><>\n", threadSafeQueue.PeakBack());

    threadSafeQueue.PushFront(100);
    printf("<><><><> QUEUE Peak Front: %u <><><><>\n", threadSafeQueue.PeakFront());
    printf("<><><><> QUEUE SIZE: %u <><><><>\n", threadSafeQueue.GetSize());

    printf("<><><><> POPPING ALL ELEMENETS IN QUEUE <><><><>\n");
    uint32_t timeoutMs = 1000;
    int count = 0;
    while (!threadSafeQueue.IsEmpty())
    {
        printf("Count: %i\n", ++count);
        threadSafeQueue.Pop(timeoutMs);
    }
    printf("<><><><> QUEUE SIZE: %u <><><><>\n", threadSafeQueue.GetSize());
    printf("<><><><> END <><><><>\n");
    
    return 0;
}
