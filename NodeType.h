#ifndef H_NodeType
#define H_NodeType

template <class Type>
struct NodeType
{
	Type info;
	NodeType<Type> *link;
};

#endif