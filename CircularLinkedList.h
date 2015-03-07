#ifndef H_CircularLinkedList
#define H_CircularLinkedList

template <class Type>
class circularLinkedList
{
protected:
	int count; //variable to store the number of elements in the list
	nodeType<Type> *first; //pointer to the first node of the list
	nodeType<Type> *last; //pointer to the last node of the list
private:
	void copyList(const circularLinkedList<Type>& otherList);
	//Function to make a copy of otherList.
public:
	const circularLinkedList<Type>& operator=(const circularLinkedList<Type>&);
	//Overloads the assignment operator.
	void initializeList(); //Initializes the list to an empty state.
	bool isEmptyList(); //Function to determine whether the list is empty.
	void print() const;
	int length(); //Function to return the number of nodes in the list.
	void destroyList(); //Function to delete all the nodes from the list.
	Type front(); //Function to return the first element of the list.
	Type back(); //Function to return the last element of the list.
	bool search(const Type& searchItem);
	void insertNode(const Type& newitem);
	void deleteNode(const Type& deleteItem);//Function to delete deleteItem from the list
	circularLinkedList(); //Default constructor
	circularLinkedList(const circularLinkedList<Type>& otherList); //Copy constructor
	~circularLinkedList(); //Destructor
};#include "CircularLinkedList.cpp"#endif