#ifndef H_CircularLinkedList
#define H_CircularLinkedList
#include "NodeType.h"

template <class Type>
class CircularLinkedList
{
public:
	const CircularLinkedList<Type>& operator=
		(const CircularLinkedList<Type>& right);
	void initializeList();
	bool isEmptyList();
	void print() const;
	int length();
	void destroyList();
	Type front();
	Type back();
	bool search(const Type& searchItem);
	void insertNode(const Type& newitem);
	void deleteNode(const Type& deleteItem);
	CircularLinkedList();
	CircularLinkedList
		(const CircularLinkedList<Type>& otherList);
	~CircularLinkedList();
protected:
	int count;
	NodeType<Type> *first; //Points the (logical) last node.
	// It is not needed using a last pointer in circularLLists.
	// nodeType<Type> *last;
private:
	void copyList(const CircularLinkedList<Type>& otherList);
};#include "CircularLinkedList.cpp"#endif