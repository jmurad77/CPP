// StudingInterviews.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sorting.h"

int main()
{
    uint32_t arr[] = {10, 69, 77, 27, 17, 1000,2, 5000, 324};
    size_t arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("<><><><><> ARRAY BEFORE QUICK SORT <><><><><>\n");
    PrintArr(arr, arrSize);
    
    // Perform Quick Sort of array
    QuickSort(arr,arrSize);
    printf("<><><><><> ARRAY AFTER QUICK SORT <><><><><>\n");
    PrintArr(arr, arrSize);

    return 0;
}
