#include "Sorting.h"


int compare(const void* a, const void* b)
{
	const uint32_t* x = (uint32_t*)a;
	const uint32_t* y = (uint32_t*)b;

	if (*x > * y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}


void QuickSort(uint32_t* arr, size_t size)
{
	if (arr == NULL)
	{
		return;
	}

	qsort(arr, size, sizeof(arr[0]), compare);
}

void InsertionSort(vector<uint32_t>& vec)
{
	int j, key;
	for (unsigned int i = 1; i < vec.size(); i++)
	{
		key = vec[i];
		j = i - 1;

		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		vec[j + 1] = key;
	}
}

void std_sort(vector<uint32_t>& vec)
{
	sort(vec.begin(), vec.end());
}

void swap_uint32_t(uint32_t& a, uint32_t& b)
{
	a = a - b;
	b = a + b;
	a = b - a;
}

void PrintArr(uint32_t* arr, const size_t size)
{
	printf("ARRAY DATA: ");
	for (uint32_t i = 0; i < size; i++)
	{
		printf("%u ", arr[i]);
	}
	printf("\n");
}