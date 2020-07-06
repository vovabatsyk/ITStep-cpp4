#pragma once
#include"List.h"

template<class T>
class cqueue
{
	List<T> list;

public:
	cqueue() = default;
	bool empty();
	size_t size();
	const T& front();
	void enqueue(const T& value);
	void dequeue();
	void clear();
};

template<class T>
bool cqueue<T>::empty()
{
	return list.empty();
}

template<class T>
size_t cqueue<T>::size()
{
	return list.size();
}

template<class T>
const T& cqueue<T>::front()
{
	return list.front();
}

template<class T>
void cqueue<T>::enqueue(const T& value)
{
	list.push_back(value);
}

template<class T>
void cqueue<T>::dequeue()
{
	list.pop_front();
}

template<class T>
void cqueue<T>::clear()
{
	list.clear();
}
