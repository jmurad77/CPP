#include <iostream>
#include <cstdlib>
#include <time.h> 
#include "LinkList.h"

using namespace std;

int main()
{
    printf("<><><><> CREATING LINK LIST <><><><>\n");
    LinkList list;

    srand(time(0));
    uint32_t numberOfAppToList = 20000;
    printf("<><><><> APPENDING %u ITEMS TO LINK LIST <><><><>\n", numberOfAppToList);
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfAppToList; i++)
    {
        list.AppendNodeSorted((rand() % 20000) + 1);
    }
    auto end = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    double finalTime = time_taken * 1e-9;
    printf("<><><><> TIME TAKEN TO APPEND %u ELEMENTS TO LIST, TIME: %f(s) <><><><>\n", numberOfAppToList, finalTime);

    printf("<><><><> DELETING ALL ITEMS BUT THE LAST 10 FROM THE LINK LIST <><><><>\n");
    for (int i = 0; i < numberOfAppToList-10; i++)
    {
        list.DeleteHead();
    }

    printf("<><><><> SIZE OF LIST: %u\n", list.GetSize());
    list.Print();
    printf("<><><><> END <><><><>\n");

    return 0;
}
