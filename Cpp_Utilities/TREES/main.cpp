#include <iostream>
#include <chrono>
#include "Tree.h"

using namespace std;

int main()
{
    printf("<><><><> STARTING TREE DATA STRUCTURES <><><><>\n");
    Tree items;
    srand(time(0));
    unsigned int appendItems = 100000;
    printf("<><><><> APPENDING %u ITEMS TO TREE <><><><>\n", appendItems);
    for (unsigned int i = 0; i < appendItems; i++)
    {
        items.AppendNode(rand() % appendItems);
    }
    //items.PrintTree();

    unsigned int findNumber = 7;
    auto start = chrono::high_resolution_clock::now();
    bool ret = items.FindNode(findNumber);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    printf("TIME TO FIND NUMBER: %u, IN TREE DATA STRUCTURE: %f (s), FOUND: %d\n",findNumber, time_taken, ret);
    printf("<><><><> END <><><><>\n");

    return 0;
}
