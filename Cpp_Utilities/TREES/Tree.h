#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <iostream>
#include <stdint.h>

using namespace std;

struct Node
{
	Node* right;
	Node* left;
	unsigned int value;
	Node(unsigned int val)
	{
		this->value = val;
		this->right = NULL;
		this->left = NULL;
	}
};

class Tree
{
private:
	Node* myHead;
	void AddNewNode(Node** node, unsigned int value);
	void PrintNextNode(Node* node);
	bool FindNodeRec(Node* node, unsigned int value);

public:
	Tree();
	Tree(unsigned int value);
	void PrintTree();
	void AppendNode(unsigned int value);
	bool FindNode(unsigned int value);
	//void DeleteNode(unsigned int value);
};
#endif