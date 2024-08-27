#include "StlDataStructures.h"

// Is Sorted
// Map Insert, erase O(log n)
// Map find O(1)
// Elements if repeated will get overwritten, but not with insert
void Map_Example()
{
	map<int, string> IdAndName;
	IdAndName[256] = "JOHN";
	IdAndName[69] = "JOHNITH";
	IdAndName[100] = "Sally";
	IdAndName[256] = "JOHN REPEAT";
	IdAndName.insert(make_pair(10, "PETER"));
	IdAndName.insert(make_pair(200, "Paul"));
	IdAndName.insert(make_pair(300, "Layla"));
	// To erase a range
	// IdAndName.erase(IdAndName.begin(), IdAndName.find(100));
	// To erase an element
	IdAndName.erase(100);

	printf("PRINTING MAP, SIZE: %li\n", IdAndName.size());
	for (auto it = IdAndName.begin(); it != IdAndName.end(); it++)
	{
		printf("KEY: %i,\t VALUE: %s\n", it->first, it->second.c_str());
	}
	printf("\n\n");
}

// Is sorted
// Can have multiple key values
void Multi_Map_Example()
{
	multimap<int, string> IdAndName;
	IdAndName.insert({256,"JOHN"});
	IdAndName.insert({69, "JOHNITH"});
	IdAndName.insert({100, "JOHNITH"});
	IdAndName.insert({256, "JOHN REPEAT"});
	IdAndName.insert(make_pair(10, "PETER"));
	IdAndName.insert(make_pair(200, "Paul"));
	IdAndName.insert(make_pair(300, "Layla"));

	// To erase an element
	IdAndName.erase(100);

	printf("PRINTING MULTI MAP, SIZE: %li\n", IdAndName.size());
	for (auto it = IdAndName.begin(); it != IdAndName.end(); it++)
	{
		printf("KEY: %i,\t VALUE: %s\n", it->first, it->second.c_str());
	}

	// This is how to access all the multi map Keys
	auto range = IdAndName.equal_range(256);
	for (auto it = range.first; it != range.second; ++it)
	{
		printf("ID: %i, NAME: %s\n", it->first, it->second.c_str());
	}
	printf("\n\n");
}

// Treat this almost as a linked list that have no order
// Difference from linked list is you have a hash and don't have to traverse the whole map
void Unordered_Map_Example()
{
	unordered_map<int, string> IdAndName;
	IdAndName[256] = "JOHN";
	IdAndName[69] = "JOHNITH";
	IdAndName[100] = "Sally";
	IdAndName.insert({256,"JOHN REPEAT"}); 	// If you insert and it exist it won't override
	IdAndName[256] = "JOHN REPEAT Elem";  	// But this will override the elements if it does exist or create a new element
	IdAndName.insert(make_pair(10, "PETER"));
	IdAndName.insert(make_pair(200, "Paul"));
	IdAndName.insert(make_pair(300, "Layla"));

	// To erase an element
	IdAndName.erase(100);

	printf("PRINTING UNORDERED MAP, SIZE: %li\n", IdAndName.size());
	for (auto it = IdAndName.begin(); it != IdAndName.end(); it++)
	{
		printf("KEY: %i,\t VALUE: %s\n", it->first, it->second.c_str());
	}
	printf("\n\n");
}

// Sets are good if you need a sorted amount of elements
void Set_Example()
{
	set<string> Names = {"JOHN", "LAYLA", "SALLY"};
	Names.insert("JOHN REPEAT");
	Names.insert("PETER");
	Names.insert("Paul");
	// To erase a range
	// Names.erase(Names.begin(), Names.find(100));
	// To erase an element
	Names.erase("PETER");

	auto iterName = Names.find("JOHN");
	if (iterName != Names.cend())
	{
		// For sets to replace an elements you must erase then insert again
		Names.erase(iterName);
		Names.insert("JOHN REPLACED");
	}
	// You can erase the begining of the List
	Names.erase(Names.begin());
	// Erase the end of the List
	Names.erase(--Names.end());

	printf("PRINTING SET, SIZE: %li\n", Names.size());
	for (auto it = Names.begin(); it != Names.end(); it++)
	{
		printf("KEY NAME: %s\n", it->c_str());
	}
	printf("\n\n");
}

void Multi_Set_Example()
{
	multiset<string> Names = {"JOHN", "LAYLA", "SALLY"};
	Names.insert("JOHN REPEAT");
	Names.insert("PETER");
	Names.insert("Paul");
	// To erase a range
	// Names.erase(Names.begin(), Names.find(100));
	// To erase an element
	Names.erase("PETER");

	// You can have more than one of the same type
	Names.insert("JOHN");
	Names.insert("JOHN");
	// You can erase the begining of the List
	Names.erase(Names.begin());
	// Erase the end of the List
	Names.erase(--Names.end());

	printf("PRINTING MULTI SET, SIZE: %li\n", Names.size());
	for (auto it = Names.begin(); it != Names.end(); it++)
	{
		printf("KEY NAME: %s\n", it->c_str());
	}

	// This is how to access all the multi Set Keys
	auto range = Names.equal_range("JOHN");
	for (auto it = range.first; it != range.second; ++it)
	{
		printf("NAME: %s\n", it->c_str());
	}
	printf("\n\n");
}

// Doesn't ahve erase at the end
void Unordered_Set_Example()
{
	unordered_set<string> Names = {"JOHN", "LAYLA", "SALLY"};
	Names.insert("JOHN REPEAT");
	Names.insert("PETER");
	Names.insert("Paul");
	// To erase a range
	// Names.erase(Names.begin(), Names.find(100));
	// To erase an element
	Names.erase("PETER");

	auto iterName = Names.find("JOHN");
	if (iterName != Names.cend())
	{
		// For sets to replace an elements you must erase then insert again
		Names.erase(iterName);
		Names.insert("JOHN REPLACED");
	}
	// You can erase the begining of the List
	Names.erase(Names.begin());
	// Doesn't have end erase
	//Names.erase(--Names.end());

	printf("PRINTING UNORDERED SET, SIZE: %li\n", Names.size());
	for (auto it = Names.begin(); it != Names.end(); it++)
	{
		printf("KEY NAME: %s\n", it->c_str());
	}
	printf("\n\n");
}

// This is equivalent to a doubly Linked list
// can reverse list
// cna sort
// Can eliminate duplicates
void List_Example()
{
	list<int> numbers = {-100, 69, 17, 59, 77, 10};
	numbers.pop_back();
	numbers.pop_front();

	// reverses the list, probably just swaps head and tail
	numbers.reverse();
	numbers.emplace_back(3000);

	// Can sort
	numbers.sort();
	printf("PRINTING LIST, SIZE: %li\n", numbers.size());
	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		printf("%i ", *it);
	}
	printf("\n\n");
}

// Can remove unique any duplicates
// Can eliminate duplicates
// doesn't ahve built in sorting
void Forward_List_Example()
{
	forward_list<int> flist = {10, 20 , 30, 40, 5, 1, 1, 30};

	flist.push_front(-100);
	flist.unique();

	printf("PRINTING FORWARD LIST, MAX SIZE: %li\n", flist.max_size());
	for (auto it = flist.begin(); it != flist.end(); it++)
	{
		printf("%i ", *it);
	}
	printf("\n\n");
}

// Can only add elements to the front of the queue
void Queue_Example()
{
	queue<int> q;
	q.emplace(10);
	q.emplace(15);
	q.emplace(20);
	q.emplace(30);
	q.emplace(-100);
	q.emplace(35);

	printf("PRINTING QUEUE, SIZE: %li\n", q.size());
	printf("FRONT ELEM OF QUEUE: %i\n", q.front());
	printf("LAST ELEM OF QUEUE: %i\n", q.back());
	while (!q.empty())
	{
		int ret = q.front();
		q.pop();
		printf("%i ", ret);
	}
	printf("\n\n");
}

// Can add elements to the front and back of the queue
void Deque_Example()
{
	deque<int> q;
	q.push_back(10);
	q.push_back(15);
	q.push_back(20);
	q.push_back(30);
	q.push_back(-100);
	q.push_back(35);
	q.push_front(77);
	q.push_front(1000);

	printf("PRINTING DEQUE, SIZE: %li\n", q.size());
	printf("FRONT ELEM OF QUEUE: %i\n", q.front());
	printf("LAST ELEM OF QUEUE: %i\n", q.back());
	while (!q.empty())
	{
		int ret = q.front();
		q.pop_front();
		printf("%i ", ret);
	}
	printf("\n\n");
}

// LIFO Last in first out data structure that is a singly linked list
void Stack_Example()
{
	stack<int> st;
	st.push(69);
	st.push(57);
	st.push(1000);
	st.push(77);
	st.push(500);
	st.push(677);

	printf("PRINTING STACK, SIZE: %li\n", st.size());
	while (!st.empty())
	{
		printf("%i ", st.top());
		st.pop();
	}

	printf("\n\n");
}

// Fancy Array with functions. Has O(n) for insert
void Vector_Example()
{
	vector<int> vec = {10, 20, 5, 30};
	vec.push_back(69);
	vec.insert(vec.begin(), 11);
	vec.insert(vec.begin() + 2, 22);
	vec.pop_back();
	vec.shrink_to_fit();
	vec.push_back(888);

	// Deletes the last element in vector, This is a pop_front
	vec.erase(--vec.end());

	printf("PRINTING VECTOR, SIZE: %li, CAPACITY: %li\n", vec.size(), vec.capacity());
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		printf("%i ", *it);
	}
	printf("\n\n");
}

// just a object version of an arrray
// can use std::sort on it
void Array_Example()
{
	array<int, 10> arr = {10, 20, 5, 30, 15, 69, 77, 32, 19, 43};
	std::sort(arr.begin(), arr.end());

	// Will set the array with this default value
	//arr.fill(69);

	printf("PRINTING ARRAY, SIZE: %li, FIRST ELEM: %i, LAST ELEM: %i\n", arr.size(), arr[0], arr[arr.size()-1]);
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		printf("%i ", *it);
	}
	printf("\n\n");
}