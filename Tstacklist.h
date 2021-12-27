#pragma once
#include "node.h"
template <class T>
class Tstacklist {
private:
	TNode<T>* pFirst;
public:
	Tstacklist() {
		pFirst = nullptr;
	};

	Tstacklist(const Tstacklist<T>& tmp) {
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
	};

	~Tstacklist() 
	{
		TNode<T>* temp;
		while (pFirst != nullptr) {
			temp = pFirst;
			pFirst = pFirst->pNext;
			delete temp;
		}
	}

	void push(T item) {
		TNode<T>* newNode = new TNode<T>();
		newNode->value = item;
		newNode->pNext = pFirst;
		pFirst = newNode;
	}

	T pop() {
		T value = pFirst->value;
		TNode<T>* oldFirst = pFirst;
		pFirst = oldFirst->pNext;
		delete oldFirst;
		return value;
	}

	T top() const
	{
		return pFirst->value;
	}

	bool IsEmpty() const
	{
		return pFirst == nullptr;
	}

	bool operator==(const Tstacklist<T>& tmp) const {
		TNode<T>* node = pFirst;
		TNode<T>* tmpNode = tmp.pFirst;

		while (node != nullptr && tmpNode != nullptr)
		{
			if (node->value != tmpNode->value) {
				return false;
			}

			node = node->pNext;
			tmpNode = tmpNode->pNext;
		}

		if (node != nullptr || tmpNode != nullptr) {
			return false;
		}

		return true;
	}

	bool operator!=(const Tstacklist<T>& tmp) const {
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

	Tstacklist<T>& operator=(const Tstacklist<T>& tmp) {
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
		return*this;
	}
};
