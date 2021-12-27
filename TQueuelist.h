#pragma once
#include "node.h"
template <class T>
class TQueuelist {
private:
	TNode<T>* pFirst, * pLast;
public:
	TQueuelist() 
	{
		pFirst = pLast = nullptr;
	}

	TQueuelist(const TQueuelist& tmp)
	{
		pFirst = pLast = nullptr;
		TNode<T>* newNode;
		newNode = new TNode<T>;
		newNode->value = tmp.pFirst->value;
		newNode->pNext = nullptr;
		pFirst = newNode;
		TNode<T>* prevNode = newNode;
		TNode<T>* tmpNode = tmp.pFirst->pNext;
		while (tmpNode != nullptr)
		{
			newNode = new TNode<T>;
			newNode->value = tmpNode->value;
			newNode->pNext = nullptr;

			prevNode->pNext = newNode;

			prevNode = newNode;
			tmpNode = tmpNode->pNext;
		}
		pLast = prevNode;
	}

	~TQueuelist()
	{
		TNode<T>* Node;
		while (pFirst != nullptr)
		{
			Node = pFirst;
			pFirst = pFirst->pNext;
			delete Node;
		}
		pLast = nullptr;
	}

	void push(T elem) 
	{
		TNode<T>* newNode = new TNode<T>();
		newNode->value =elem;
		newNode->pNext = nullptr;

		if (pLast != nullptr) {
			pLast->pNext = newNode;
		}
		else {
			pFirst = newNode;

		}
		pLast = newNode;
	}

	T pop() 
	{
		T value = pFirst->value;
		TNode<T>* oldFirst = pFirst;
		pFirst = oldFirst->pNext;
		delete oldFirst;

		if (pFirst == nullptr) {
			pLast = nullptr;
		}

		return value;
	}

	bool IsEmpty()
	{
		return pFirst == nullptr;
	}

	T getfirst() 
	{
		return pFirst->value;
	}

	T getlast() 
	{
		return pLast->value;
	}

	bool operator==(const TQueuelist<T>& tmp) 
	{
		TNode<T>* node = pFirst;
		TNode<T>* tmpNode = tmp.pFirst;

		while (node != nullptr && tmpNode != nullptr)
		{
			if (node->value != tmpNode->value) 
			{
				return false;
			}

			node = node->pNext;
			tmpNode = tmpNode->pNext;
		}

		if (node != nullptr || tmpNode != nullptr) 
		{
			return false;
		}
		return true;
	}

	bool operator!=(const TQueuelist<T>& tmp) 
	{
		TNode<T>* node = pFirst;
		TNode<T>* tmpNode = tmp.pFirst;

		while (node != nullptr && tmpNode != nullptr)
		{
			if (node->value != tmpNode->value) {
				return true;
			}

			node = node->pNext;
			tmpNode = tmpNode->pNext;
		}

		if (node != nullptr || tmpNode != nullptr) {
			return true;
		}
		return false;
	}

	TQueuelist<T>& operator=(const TQueuelist<T>& tmp)
	{
		pFirst = pLast = nullptr;
		TNode<T>* newNode;
		newNode = new TNode<T>;
		newNode->value = tmp.pFirst->value;
		newNode->pNext = nullptr;
		pFirst = newNode;
		TNode<T>* prevNode = newNode;
		TNode<T>* tmpNode = tmp.pFirst->pNext;
		while (tmpNode != nullptr)
		{
			newNode = new TNode<T>;
			newNode->value = tmpNode->value;
			newNode->pNext = nullptr;
			prevNode->pNext = newNode;
			prevNode = newNode;
			tmpNode = tmpNode->pNext;
		}
		pLast = prevNode;
		return*this;
	}
};
