#include "LinkList.h"

LinkList::LinkList()
{
	myHead = NULL;
	mySize = 0;
}

LinkList::LinkList(int value)
{
	myHead = CreateNode(value);
	mySize = 1;
}

List_Node* LinkList::CreateNode(int value)
{
	List_Node* new_node = new List_Node;
	new_node->value = value;
	new_node->next = NULL;

	return new_node;
}

void LinkList::AppendNode(int value)
{
	List_Node* new_node = CreateNode(value);

	if (myHead == NULL)
	{
		myHead = new_node;
		mySize = 1;
		return;
	}

	List_Node* last = myHead;

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	mySize++;
}

void LinkList::AppendNodeSorted(int value)
{
	List_Node* new_node = CreateNode(value);

	if (myHead == NULL)
	{
		myHead = new_node;
		mySize = 1;
		return;
	}

	// Add element to head
	if (myHead->value > value)
	{
		List_Node* temp = myHead;
		new_node->next = temp;
		myHead = new_node;
		mySize++;
		return;
	}

	List_Node* current = myHead->next;
	List_Node* prev = myHead;

	while (current != NULL)
	{
		// Find the location to insert
		if (current->value > value)
		{
			break;
		}
		current = current->next;
		prev = prev->next;
		
	}

	if (prev == NULL)
	{
		current = new_node;
	}
	else
	{
		prev->next = new_node;
		new_node->next = current;
	}	
	mySize++;
}

List_Node* LinkList::FindNode(int value)
{
	List_Node* ret = myHead;
	while (ret != NULL)
	{
		if (ret->value == value)
		{
			return ret;
		}
		ret = ret->next;
	}
	return NULL;
}

void LinkList::DeleteHead()
{
	if (myHead == NULL)
	{
		return;
	}

	List_Node* temp = myHead;
	myHead = myHead->next;
	delete temp;
	mySize--;
}

void LinkList::DeleteTail()
{
	if (myHead == NULL)
	{
		return;
	}
	else if (myHead->next == NULL)
	{
		List_Node* temp = myHead->next;
		delete temp;
		myHead->next = NULL;
		mySize--;
		return;
	}

	List_Node* deleteTail = myHead->next;
	List_Node* prev = myHead;
	while (deleteTail != NULL)
	{
		if (deleteTail->next == NULL)
		{
			break;
		}
		deleteTail = deleteTail->next;
		prev = prev->next;
	}

	delete deleteTail;
	prev->next = NULL;
	mySize--;
}

void LinkList::DeleteNode(int value)
{
	if (myHead == NULL)
	{
		return;
	}

	if (myHead->value == value)
	{
		this->DeleteHead();
		mySize--;
		return;
	}

	List_Node* deleteNode = myHead->next;
	List_Node* prev = myHead;
	while (deleteNode != NULL)
	{
		if (deleteNode->value == value)
		{
			prev->next = deleteNode->next;
			delete deleteNode;
			mySize--;
			return;
		}
		deleteNode = deleteNode->next;
		prev = prev->next;
	}
	// Didn't find node don't delete
}

bool LinkList::IsEmpty()
{
	return mySize == 0;
}

unsigned int LinkList::GetSize()
{
	return mySize;
}

void LinkList::Print()
{
	if (myHead == NULL)
	{
		return;
	}

	List_Node* printNode = myHead;
	while (printNode != NULL)
	{
		printf("%d - ", printNode->value);
		printNode = printNode->next;
	}
	printf("\n");
}