#pragma once
#include<iostream>
#include <stdexcept>
using namespace std;

template<class T>
class List
{
public:
	List();
	List(const List& other);
	~List();

	int size()const;
	T& front()const;
	T& back()const;
	bool empty()const;
	int index_of(const T& value);
	void clear();
	void remove_at(int index);
	void remove(const T& value);

	void push_back(const T data);
	void push_front(const T data);
	void insert(const T data, int index);
	void pop_front();
	void pop_back();

	bool operator ==(const List& other);
	bool operator !=(const List& other);
	List& operator =(const List& other);
	T& operator[](const int index);

	template<class T>
	friend ostream& operator<<(ostream& out, List<T>& list);

private:
	template<class T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int length;
	Node<T>* head;
};

template<class T>
List<T>::List()
{
	length = 0;
	head = nullptr;
}

template<class T>
List<T>::List(const List& other)
{
	Node<T>* current = other.head;

	while (current)
	{
		push_back(current->data);
		current = current->pNext;
	}
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
int List<T>::size() const
{
	return length;
}

template<class T>
bool List<T>::empty() const
{
	return !head;
}

template<class T>
int List<T>::index_of(const T& value)
{
	int pos = 0;
	int count = length;
	Node<T>* temp = head;

	while (count)
	{
		if (temp->data == value)
		{
			return pos;
		}
		temp = temp->pNext;
		count--;
		pos++;
	}
	return -1;
}

template<class T>
void List<T>::clear()
{
	while (length)
	{
		pop_front();
	}
}

template<class T>
void List<T>::remove_at(int index)
{
	if (index == 0)
	{
		pop_front();

	}
	else if (index <= length)
	{
		Node<T>* prev = head;
		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}
		Node<T>* toDelete = prev->pNext;
		prev->pNext = toDelete->pNext;
		delete toDelete;
		length--;
	}
	else
	{
		throw exception("position not found");
	}
}

template<class T>
void List<T>::remove(const T& value)
{
	int pos = index_of(value);
	if (pos >= 0)
		remove_at(pos);
}

template<class T>
void List<T>::push_back(const T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	length++;
}

template<class T>
void List<T>::push_front(const T data)
{
	head = new Node<T>(data, head);
	length++;
}

template<class T>
void List<T>::insert(const T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else if (index <= length)
	{
		Node<T>* prev = head;
		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}
		prev->pNext = new Node<T>(data, prev->pNext);
		length++;
	}
	else
	{
		throw exception("position not found");
	}

}

template<class T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	length--;
}

template<class T>
void List<T>::pop_back()
{
	remove_at(length - 1);
}

template<class T>
bool List<T>::operator==(const List& other)
{
	return size() == other.size();
}

template<class T>
bool List<T>::operator!=(const List& other)
{
	return size() != other.size();
}

template<class T>
List<T>& List<T>::operator=(const List& other)
{
	if (this == &other)
		return *this;
	clear();
	Node<T>* current = other.head;
	while (current)
	{
		push_back(current->data);
		current = current->pNext;
	}
	return *this;
}



template<class T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}

template<class T>
T& List<T>::front() const
{
	return this->head->data;
}

template<class T>
inline T& List<T>::back() const
{
	Node<T>* current = head;

	while (current->pNext != nullptr)
	{
		current = current->pNext;
		if (current->pNext == nullptr)
			return current->data;
	}
}

template<class T>
ostream& operator<<(ostream& out, List<T>& list)
{
	for (int i = 0; i < list.size(); i++)
		cout << list[i] << "\t";
	return out;
}
