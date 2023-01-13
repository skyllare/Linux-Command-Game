#pragma once
#include "node.h"

template <class T>
class List
{
public:
	List<T>(Node<T>* newpHead = nullptr);

	Node<T>* getHead();
	void setHead(Node<T>* newHead);
	/*
		Function Name: insertNode
		Description: puts node in start of list
	*/
	void insertNode(T newData);

	int countNodes();

	

private:
	Node<T>* pHead;

};

template<class T>
inline List<T>::List(Node<T>* newpHead)
{
	this->pHead = pHead;
}

template<class T>
inline Node<T>* List<T>::getHead()
{
	return this->pHead;
}

template<class T>
inline void List<T>::setHead(Node<T>* newHead)
{
	this->pHead = newHead;
}

template<class T>
inline void List<T>::insertNode(T newData)
{
	Node<T>* pMem = new Node<T>(newData);


	if (pMem != nullptr)
	{
		if (pHead == nullptr)
		{
			pHead = pMem;
		}
		else
		{

			pMem->setNext(pHead);
			pHead = pMem;
		}
	}
}

template<class T>
inline int List<T>::countNodes()
{
	Node<T>* pCur = this->getHead();
	int i = 0;
	do
	{
		pCur = pCur->getNext();
		i++;

	} while (pCur->getNext() != nullptr);

	return i;
}


