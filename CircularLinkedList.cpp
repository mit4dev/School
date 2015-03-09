#include <iostream>
using namespace std;

#ifndef CPP_CircularLinkedList
#define CPP_CircularLinkedList
#include "CircularLinkedList.h"

template <class Type>
const CircularLinkedList<Type>& CircularLinkedList<Type>::operator=
(const CircularLinkedList<Type>& right)
{
	copyList(right);
}

template <class Type>
void CircularLinkedList<Type>::initializeList()
{
	destroyList();
}


template <class Type>
bool CircularLinkedList<Type>::isEmptyList()
{
	return (first == NULL);
}

template <class Type>
void CircularLinkedList<Type>::print()const
{
	NodeType<Type> *current;
	current = first->link;
	if(!isEmptyList())
	{
		cout << "Printing List.." << endl;
		while(current != first)
		{
			cout << current->info << " ";
			current = current->link;
		}
		cout << "\nEnd Print.." << endl;
	}
}

template <class Type>
int CircularLinkedList<Type>::length()
{
	return count;
}

template <class Type>
void CircularLinkedList<Type>::destroyList()
{
	NodeType<Type> *current;
	if(!isEmptyList())
	{
		current = first->link;
		first->link = NULL;
		first = current; // first points to the
						 // first node, and the last
						 // node's link is set to NULL.
						 // so we have an ending point.
		while(first != NULL)
		{
			current = first;
			first = first->link;
			delete current;
		}
		count = 0;
	}
}

template <class Type>
Type CircularLinkedList<Type>::front()
{
	return (first->link->info);
}

template <class Type>
Type CircularLinkedList<Type>::back()
{
	return (first->info);
}

template <class Type>
bool CircularLinkedList<Type>::search(
	const Type& searchItem)
{
	NodeType<Type> *current;
	bool found;
	if(!isEmptyList())
	{
		found = false;
		current = first->link;
		while(current != first)
		{
			if(current->info >= searchItem)
				found = true;
			else
				current = current->link;
		}
	}
	return (current->info == searchItem);
}

template <class Type>
void CircularLinkedList<Type>::insertNode(
	const Type& newItem)
{
	NodeType<Type> *trail, *current, *newNode;
	newNode = new NodeType < Type > ;
	newNode->info = newItem;
	bool found = false;

	if(first == NULL)
	{
		first = newNode;
		first->link = first;
		count++;
	}
	else
	{
		trail = current = first->link;
		while(current != first && !found)
		{
			if(current->info >= newItem)
				found = true;
			else
			{
				trail = current;
				current = current->link;
			}
		}
		if(current == first)
		{
			newNode->link = first->link;
			first->link = newNode;
			first = newNode;
			count++;
		}
		else if(current == first->link)
		{
			first->link = newNode;
			newNode->link = first->link;
			count++;
		}
		else
		{
			newNode->link = trail->link;
			trail->link = newNode;
			count++;
		}
	}
}

template <class Type>
void CircularLinkedList<Type>::deleteNode(
	const Type& deleteItem)
{
	NodeType<Type> *trail, *current;
	bool found = false;

	if(!isEmptyList())
	{
		trail = current = first->link;
		while(current != first && !found)
		{
			if(current->info >= deleteItem)
				found = true;
			else
			{
				trail = current;
				current = current->link;
			}
		}
		if(found && current->info == deleteItem)
		{
			if(current == first) //if last
			{
				trail->link = first->link;
				first = trail;
				count--;
				delete current;
			}
			else
			{
				trail->link = current->link;
				count--;
				delete current;
			}
			if(count == 0)
			{
				first = NULL;
			}
			if(count == 1)
			{
				first->link = first;
			}
		}
		else
		{
			cout << "Item to be deleted is not in the list."
				<< endl;
		}
	}
}

template <class Type>
CircularLinkedList<Type>::CircularLinkedList()
{
	first = NULL;
	count = 0;
}

template <class Type>
CircularLinkedList<Type>::CircularLinkedList(
	const CircularLinkedList<Type>& otherList)
{
	copyList(otherList);
}

template <class Type>
CircularLinkedList<Type>::~CircularLinkedList()
{
	destroyList();
}

template <class Type>
void CircularLinkedList<Type>::copyList(
	const CircularLinkedList<Type>& otherList)
{
	if(!(*this == otherList&))
	{
		NodeType<Type> *current, *newNode;

		if(otherList->first == NULL)
		{
			first = NULL;
			count = 0;
		}
		else
		{
			current = otherList.first;
			newNode = new NodeType < Type >;
			newNode->info = current->info;
			first = newNode;
			current = current->link;
			while(current != first)
			{
				newNode = new NodeType < Type > ;
				newNode->info = current->info;
				current = current->link;
			}
			count = otherList.count;
		}
	}
}

#endif