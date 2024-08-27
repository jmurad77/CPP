#include "Tree.h"

Tree::Tree()
{
	myHead = NULL;
}

Tree::Tree(unsigned int value)
{
	myHead = new Node(value);
	myHead->value = value;
	myHead->left = NULL;
	myHead->right = NULL;
}

void Tree::PrintNextNode(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	PrintNextNode(node->left);
	cout << node->value << endl;
	PrintNextNode(node->right);
}

void Tree::PrintTree()
{
	PrintNextNode(myHead);
}

void Tree::AppendNode(unsigned int value)
{
	AddNewNode(&myHead, value);
}

void Tree::AddNewNode(Node** node, unsigned int value)
{
	if (*node == NULL)
	{
		*node = new Node(value);
		return;
	}

	if ((*node)->value > value)
	{
		this->AddNewNode(&((*node)->left), value);
	}
	else
	{
		this->AddNewNode(&((*node)->right), value);
	}
}

bool Tree::FindNode(unsigned int value)
{
	return FindNodeRec(myHead, value);
}

bool Tree::FindNodeRec(Node* node, unsigned int value)
{
	if (node == NULL)
	{
		return false;
	}

	if (node->value == value)
	{
		return true;
	}

	if (node->value > value)
	{
		return FindNodeRec(node->left, value);
	}
	else
	{
		return FindNodeRec(node->right, value);
	}
}
