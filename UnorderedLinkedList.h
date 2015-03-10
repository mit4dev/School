#include <iostream>
#include <assert.h>
using namespace std;

#ifndef Unordered_linked_list_h
#define Unordered_linked_list_h
#ifndef Linked_list_h
#include "LinkedListType.h"
#endif
template < class Type >
class UnorderedLinkedList : public LinkedListType < Type >
{
public:
	bool search(const Type& searchItem) const;
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
};

template < class Type >
bool UnorderedLinkedList< Type >::search(const Type& searchItem) const
{
	NodeType < Type > *current;
	current = first;
	bool found = false;
	while (current != NULL && !found)
	{
		if (current->data == searchItem)
		{
			found = true;
		}
		else
		{
			current = current->link;
		}
	}
	return found;
}

template < class Type >
void UnorderedLinkedList < Type > ::insertFirst(const Type& newItem)
{
	NodeType<Type> *newNode;
	newNode = new NodeType < Type > ;
	newNode->data = newItem;
	newNode->link = first;
	first = newNode;
	count++;
	if (last == NULL)
		last = newNode;
}

template < class Type >
void UnorderedLinkedList < Type > ::insertLast(const Type& newItem)
{
	NodeType<Type> *newNode;
	newNode = new NodeType < Type > ;
	newNode->data = newItem;
	newNode->link = NULL;


	if (first == NULL)
	{
		//cout << "Inserted fist item: " << newNode->data << endl;
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		cout << "Inserted to the last: " << newNode->data << endl;
		last->link = newNode;
		last = newNode;
		count++;
	}
}

template < class Type >
void UnorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	NodeType<Type> *trailCurrent, *current;
	current = first;
	bool found;

	if (first == NULL)
		cout << "Cannot delete from an empty list" << endl;
	else
	{
		if (current->data == deleteItem)
		{
			current = first;
			first = first->link;
			count--;
			if (first == NULL)
				last = NULL;

			delete current;
		}
		else
		{
			found = false;
			trailCurrent = first;
			current = first->link;
			while (current != NULL && !found)
			{
				if (current->data != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}
			if (found)
			{
				trailCurrent->link = current->link;
				count--;
				if (last == current)
					last = trailCurrent;
				delete current;
			}
			else
				cout << "The item to be deleted is not in the list." << endl;
		}
	}


}

#endif