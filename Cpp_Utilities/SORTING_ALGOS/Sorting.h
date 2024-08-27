#ifndef SORTING_H
#define SORTING_H

#include <stdint.h>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>

using namespace std;

int compare(const void* a, const void* b);
void QuickSort(uint32_t* arr, size_t size);
void InsertionSort(vector<uint32_t> &vec);
void swap_uint32_t(uint32_t & a, uint32_t & b);
void std_sort(vector<uint32_t>& vec);
void PrintArr(uint32_t* arr, const size_t size);

#endif