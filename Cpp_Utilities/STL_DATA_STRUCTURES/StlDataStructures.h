#ifndef STL_DATA_STRUCTURES_H
#define STL_DATA_STRUCTURES_H

#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <array>

using namespace std;

void Map_Example();
void Multi_Map_Example();
void Unordered_Map_Example();
void Set_Example();
void Multi_Set_Example();
void Unordered_Set_Example();
void List_Example();
void Forward_List_Example();
void Queue_Example();
void Deque_Example();
void Stack_Example();
void Vector_Example();
void Array_Example();


// NOTES!
// Unordered is always faster than order structures O(1) vs O(log n)
// Stacks are Link List with just a head LIFO (Last in First Out), O(1)
// Queues are Link List with a head and tail, O(1)
// Dequeue are doubly Linked Lists with a head and tail, push_front and back, O(1)
// Sets, red-black trees, Sorted, only one unique element, O(long(n))
// (unordered_map and unordered Set), Hash table, Not sorted, only one unique element, O(1)
// (map, set, multimap and muliset), all use red-black tree, (Insert, Lookup, Deletion) = O(log n)
// List data structure is the same as a double link list



#endif