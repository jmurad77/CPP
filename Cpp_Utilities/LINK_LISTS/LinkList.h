#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <chrono>

struct List_Node
{
    List_Node* next;
    int value;
};

class LinkList
{
private:
    unsigned int mySize;
    List_Node* myHead;
    List_Node* CreateNode(int value);
public:
    LinkList();
    LinkList(int value);
    void AppendNode(int value);
    void AppendNodeSorted(int value);
    void DeleteNode(int value);
    void DeleteHead();
    void DeleteTail();
    unsigned int GetSize();
    bool IsEmpty();
    List_Node* FindNode(int value);
    void Print();
};
#endif