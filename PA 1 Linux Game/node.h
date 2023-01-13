#include "header.h"


template <class T>
class Node
{
public:
	Node(T newData = 0, Node* newpNext = nullptr);

	Node<T>* getNext();
	T& getData();

	
	void setNext(Node<T>* newNext);
	

private:
	T data;
	Node<T>* pNext;

};

template<class T>
Node<T>::Node(T newData, Node<T>* newpNext)
{
	this->data = newData;
	this->pNext = nullptr;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	return this->pNext;
}

template<class T>
T& Node<T>::getData()
{
	return this->data;
}

template<class T>
void Node<T>::setNext(Node<T>* newNext)
{
	this->pNext = newNext;
}


