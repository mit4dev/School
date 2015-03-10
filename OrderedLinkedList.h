#include <iostream>
using namespace std;

#ifndef Ordered_linked_list_h
#define Ordered_linked_list_h

#ifndef Linked_list_h
#include "LinkedListType.h"
#endif

template < class Type >
class OrderedLinkedList : public LinkedListType < Type >
{
public:
	bool search(const Type& searchItem)const;
	void insert(const Type& newItem);
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
private:
	void sort();
};

template <class Type>
bool OrderedLinkedList < Type > ::search(const Type& searchItem)const
{
	NodeType < Type > *current; //pointer to traverse the list
	bool found = false;
	current = first;

	while(current != NULL && !found)
	{
		if(current->data >= searchItem)
			found = true;
		else
			current = current->link;
	}
	if(found)
		found = (current->data == searchItem);
	return found;
}

template < class Type >
void OrderedLinkedList < Type > ::insert(const Type& newItem)
{
	NodeType < Type > *trailCurrent, *current, *newNode;
	newNode = new NodeType < Type > ;
	newNode->data = newItem;
	newNode->link = NULL;
	bool found;
	//if list empty.
	if(first == NULL)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		trailCurrent = current = first;
		found = false;
		while(current != NULL && !found)
		{
			if(current->data >= newItem)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}// if it's first node.
		if(current == first)
		{
			newNode->link = first;
			first = newNode;
			count++;
		}
		else
		{	//somewhere middle in the list.
			trailCurrent->link = newNode;
			newNode->link = current;
			//if it's the last node.
			if(current == NULL)
			{
				last = newNode;
			}
			count++;
		}
	}
}


template <class Type>
void OrderedLinkedList < Type > ::insertFirst(const Type& newItem)
{
	insert(newItem);
}

template < class Type >
void OrderedLinkedList < Type > ::insertLast(const Type& newItem)
{
	insert(newItem);
}

/*template < class Type >
void OrderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	NodeType<Type> *current, *trailCurrent;
	bool found = false;
	if(first == NULL)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		trailCurrent = current = first;
		while(current != NULL && !found)
		{
			if(first->data == deleteItem)
			{
				first = first->link;
				delete current;
				found = true;
				break;
			}
			if(current->data >= deleteItem)
			{
				trailCurrent->link = current->link;
				delete current;
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		if(!found)
			cout << "Delete failed, Cannot find the item in the list." << endl;
	}

}*/

template < class Type >
void OrderedLinkedList<Type> ::deleteNode(const Type& deleteItem)
{
	NodeType<Type> *trailCurrent, *current;
	bool found = false;
	if(first == NULL)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		trailCurrent = current = first;
		while(current != NULL && !found)
		{
			if(current->data >= deleteItem)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		if(current == NULL)
			cout << "The item to be deleted is not in the list." << endl;
		else
		{
			if(current->data == deleteItem)
			{
				if(first == current)
				{
					first = first->link;
					if(first == NULL)
						last = NULL;

					delete current;
				}
				else
				{
					cout << "DEBUG: " << endl;
					trailCurrent->link = current->link;
					cout << "DEBUG: trailcurent-link = current->link;" << endl;
					cout << "DEBUG: last->data before assignment." << last->data << endl;
					if(current == last)
					{
						last = trailCurrent;
						cout << "DEBUG: last->data after assignment." << last->data << endl;
					}
					delete current;
				}
				count--;
			}
			else
			{
				cout << "The item to be deleted is not in the list." << endl;
			}
		}
	}
}

#endif