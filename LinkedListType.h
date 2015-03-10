#include <iostream>
#include <assert.h>
using namespace std;

#ifndef Linked_list_h
#define Linked_list_h
#include "LinkedListIteratorType.h"
#include "NodeType.h"
																		
template < class Type >
class LinkedListType
{
public:
	const LinkedListType<Type>& operator= (const LinkedListType<Type>&);
	void initializeList(); 
	bool isEmptyList() const; 
	void print() const; 
	int length() const; 
	void destroyList(); 		
	Type front() const; 
	Type back() const;
	void reverseList();
	virtual bool search(const Type& searchItem) const = 0; 
	virtual void insertFirst(const Type& newItem) = 0; 
	virtual void insertLast(const Type& newItem) = 0; 
	virtual void deleteNode(const Type& deleteItem) = 0; 
	LinkedListIterator<Type> begin(); 
	LinkedListIterator<Type> end();
	LinkedListType(); 
	LinkedListType(const LinkedListType<Type>& otherList); 
	~LinkedListType();
protected:
	int count; 
	NodeType<Type> *first;
	NodeType<Type> *last;
private:
	void copyList(const LinkedListType<Type>& otherList); 
};

template < class Type >
const LinkedListType<Type>& LinkedListType<Type>::operator=(const LinkedListType<Type>& otherList)
{
	if (this != &otherList)
	{
		copyList(otherList);
	}
	return *this;
}

template < class Type >
bool LinkedListType<Type>::isEmptyList()const
{
	return (first == NULL);
}

template < class Type >
LinkedListType<Type>::LinkedListType()
{
	this->first = NULL;
	this->last = NULL;
	this->count = 0;
}

template < class Type >
LinkedListType<Type>::LinkedListType(const LinkedListType<Type>& otherList)
{
	this->copyList(otherList);
}

template < class Type >
void LinkedListType < Type > ::destroyList()
{
	NodeType<Type> *ptr;
	while (first != NULL)
	{
		ptr = first;
		first = first->link;
		delete ptr;
	}
	last = NULL;
	count = 0;
}

template < class Type >
void LinkedListType<Type>::initializeList()
{
	destroyList();
}

template < class Type >
void LinkedListType<Type>::print()const
{
	NodeType < Type > *current;
	current = first;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->link;
	}
	cout << "Total Count: " << count << endl;
}

template < class Type >
int LinkedListType < Type > ::length()const
{
	return count;
}

template < class Type >
LinkedListType < Type > ::~LinkedListType()
{
	destroyList();
}


template < class Type >
Type LinkedListType < Type > ::front()const
{
	assert(first != NULL);

	return first->data;
}

template < class Type >
Type LinkedListType < Type > ::back()const
{
	assert(last != NULL);

	return last->data;
}

template < class Type >
LinkedListIterator < Type >  LinkedListType < Type > ::begin()
{
	LinkedListIterator < Type > temp(first);
	return temp;
}

template < class Type >
LinkedListIterator< Type > LinkedListType<Type>::end()
{
	LinkedListIterator < Type > temp(last);
	return temp;
}

template < class Type >
void LinkedListType<Type>::copyList(const LinkedListType<Type>& otherList)
{
	NodeType < Type > *newNode;
	NodeType < Type > *current;
	if (first != NULL)
	{
		destroyList();
	}
	if (otherList.first == NULL)
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first;
		count = otherList.count;
		first = new NodeType < Type > ;
		first->data = current->data;
		first->link = NULL;
		last = first;
		current = current->link;
		while (current != NULL)
		{
			newNode = new NodeType < Type > ;
			newNode->data = current->data;
			newNode->link = NULL;

			last->link = newNode;
			last = newNode;

			current = current->link;
		}
	}
}

template <class Type>
void LinkedListType<Type>::reverseList()
{
	NodeType<Type> *current, *nextCurrent, *tmp;
	if(!isEmptyList())
	{
		//cout << "****reverseList function called****" << endl;
		current = first;
		nextCurrent = current->link;
		while(nextCurrent != last)
		{
			tmp = nextCurrent;
			nextCurrent = nextCurrent->link;
			tmp->link = current;
			current = tmp;
			
		}
		first->link = NULL;
		nextCurrent->link = current;
		tmp = first;
		first = last;
		last = tmp;
	}

}

#endif