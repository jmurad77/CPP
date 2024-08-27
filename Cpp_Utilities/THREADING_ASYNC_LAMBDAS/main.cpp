// StudingInterviews.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Threading_Async_Lambdas.h"

int main()
{
    // How to strongly Type Data to throw compiler errors
    using IntWidth = StrongType<Domain::Width, int32_t>;
    using IntTemperature = StrongType<Domain::Temperature, int32_t>;

    printf("<><><><> LAMBDA THREAD EXAMPLE <><><><>\n");
    LambThreads Lamb;
    printf("<><><><> I AM GOING TO STOP THE LAMBDA THREAD <><><><>\n\n");
    Lamb.Stop();
   
    // The most effcient way to push an object to a vector with not too many copies
    printf("<><><><> PUSHING A FUNCTION POINTER TO A THREAD, SHOWS PERFORMACNE OF EMPALCE BACK VS PUSH BACK INSIDE THREAD <><><><>\n");
    std::function<void()> perFunc = Test_Performance_Vector;
    auto myThread = std::thread(perFunc);
    myThread.join();
    printf("<><><><> END <><><><>\n");
    
    return 0;
}
