#pragma once
#include"List.h"

template<class T>
class cstack
{
	List<T> list = List<T>();
public:
	void push(const T& value);
	void pop();
	T& top();
	size_t size();
	bool empty();

};

template<class T>
void cstack<T>::push(const T& value)
{
	list.push_back(value);
}

template<class T>
void cstack<T>::pop()
{
	list.pop_front();
}

template<class T>
inline T& cstack<T>::top()
{
	return list.front();
}

template<class T>
inline size_t cstack<T>::size()
{
	return list.size();
}

template<class T>
bool cstack<T>::empty()
{
	return list.empty();
}
