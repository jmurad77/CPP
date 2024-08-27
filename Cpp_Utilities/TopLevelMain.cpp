// StudingInterviews.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <chrono>
#include "LinkList.h"
#include "Tree.h"
#include "Utilities.h"
#include "Sorting.h"
#include "BitMainIp.h"
#include "StlDataStructures.h"
#include "Cpp_Advanced.h"

int main()
{
    /********************
    Tree items;
    srand(time(0));
    for (unsigned int i = 0; i < 100000; i++)
    {
        items.AppendNode(rand() % 100000);
    }
    //items.PrintTree();

    unsigned int findNumber = 500;
    auto start = chrono::high_resolution_clock::now();
    bool ret = items.FindNode(findNumber);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    printf("Time to find number in Tree Data Structure: %f sec, Found: %d\n", time_taken, ret);

    unsigned int numbers[100000];
    for (unsigned int i = 0; i < 100000; i++)
    {
        numbers[i] = rand() % 100000;
    }

    ret = false;
    start = chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < 100000; i++)
    {
        if (numbers[i] == findNumber)
        {
            ret = true;
            break;
        }
    }
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    printf("Time to find number: %f sec, Found: %d\n", time_taken, ret);

    string text = "Welcome to Geeks for Geeks and even more Geeks";
    string pattern = "Geek";

    start = chrono::high_resolution_clock::now();
    pattern_search(text, pattern);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    printf("Pattern Search using List/Queues Time taken(s): %f\n", time_taken);

    start = chrono::high_resolution_clock::now();
    pattern_search_regx(text, pattern);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    printf("\nPattern Search using Regex time taken(s): %f\n\n", time_taken);
    
    // QUICK SORT
    uint32_t arr[] = { 10, 7, 558, 789, 25, 77, 2, 69 };
    QuickSort(arr, sizeof(arr)/sizeof(arr[0]));
    printf("\n\n");

    // STD SORT
    vector<uint32_t> testVec = { 10, 7, 558, 789, 25, 77, 2, 69 };
    InsertionSort(testVec);
    std_sort(testVec);
    

    uint32_t number = 0x0;
    printf("Number: 0x%X\n", number);
    Man_IP::SetBit(number, 0);
    printf("Number: 0x%X\n", number);
    Man_IP::UnSetBit(number, 5);
    printf("Number: 0x%X\n", number);
    Man_IP::ToggleBit(number, 5);
    printf("Number: 0x%X\n", number);
    Man_IP::ToggleBit(number, 5);
    printf("Number: 0x%X\n\n", number);

    Man_IP::PrintBinary(0xDEADBEEF);
    uint32_t parseData = Man_IP::GetMaskedData(0xABCD1234, 2, 2);
    printf("Parsed Data : 0x%X\n", parseData);
    printf("\n");
    Man_IP::Delete_G_Mask();

    LinkList list;
    srand(time(0));
    uint32_t numberOfAppToList = 100000;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfAppToList; i++)
    {
        list.AppendNodeSorted((rand() % 1000) + 1);
        //printf("%d\n", i+1);
    }
    auto end = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    printf("Time taken To Append %u elements to List, Time(s): %ld\n", numberOfAppToList, time_taken);

    for (int i = 0; i < numberOfAppToList/2; i++)
    {
        list.DeleteHead();
        //printf("%d\n", i + 1);
    }

    printf("Size of List: %u\n", list.GetSize());
    //list.Print();


    #ifdef TEST_OUTPUT
        cout << "TEST OUTPUT IS DEFINED\n";
    #endif

    #ifdef ANOTHER_ONE
        cout << "ANOTHERONE IS DEFINED\n";
    #endif

    uint8_t data[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xCA, 0xFE, 0xD0, 0x0D};
    uint32_t pattern = 0xCAFED00D;
    pattern_search_stream(data, pattern);
    ***********************/

    /********** START OF STL DATA STRUCTURES *******************
    Map_Example();
    Unordered_Map_Example();
    Multi_Map_Example();
    Set_Example();
    Multi_Set_Example();
    Unordered_Set_Example();
    List_Example();
    Forward_List_Example();
    Queue_Example();
    Deque_Example();
    Stack_Example();
    Vector_Example();
    Array_Example();
    ***********************/

   //using IntWidth = StrongType<Domain::Width, int32_t>;
   //using IntTemperature = StrongType<Domain::Temperature, int32_t>;

   //LambThreads Lamb;
   //printf("I AM GOING TO STOP THE THREAD\n");
   //Lamb.Stop();
   
   // The most effcient way to push an object to a vecotr with not too many copies
   std::function<void()> perFunc = Test_Performance_Vector;
   auto myThread = std::thread(perFunc);
   myThread.join();
}
