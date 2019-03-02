#pragma once
#include<cassert>

//×îÐ¡Õ»
template<typename T>
class Stack {
private:
	T* _ptr;
	T* _min;
	size_t size;
	size_t capacity;

public:
	Stack() : _ptr(nullptr), _min(nullptr), size(0), capacity(0) {}
	~Stack()
	{
		delete[] _ptr;
		delete[] _min;
		_ptr = nullptr;
		_min = nullptr;
	}
	void Push(const T& data);
	void Pop();
	T& Top();
	bool Empty();
	size_t Size();
	T Min();
	void CheckCapacity();
};

template<typename T>
T Stack<T>::Min()
{
	T num = _min[size - 1];
	return num;
}

template<typename T>
size_t Stack<T>::Size()
{
	return size;
}

template<typename T>
bool Stack<T>::Empty()
{
	return 0 == size;
}

template<typename T>
T& Stack<T>::Top()
{
	assert(0 != size);
	return _ptr[size - 1];
}

template<typename T>
void Stack<T>::Pop()
{
	if (Empty()) return;
	size--;
}

template<typename T>
void Stack<T>::Push(const T& data)
{
	CheckCapacity();
	_ptr[size] = data;
	if (0 == size)
	{
		_min[size++] = data;
		return;
	}
	T num = _min[size - 1];
	if (data > num)
		_min[size] = num;
	else
		_min[size] = data;
	size++;
}

template<typename T>
void Stack<T>::CheckCapacity()
{
	if (size < capacity)
		return;
	int NewCapacity = capacity * 2 + 3;
	T* tmp1 = new T[NewCapacity];
	T* tmp2 = new T[NewCapacity];
	for (int i = 0; i < size; ++i)
		tmp1[i] = _ptr[i];
	delete[] _ptr;
	_ptr = tmp1;
	for (size_t i = 0; i < size; ++i)
		tmp2[i] = _min[i];
	delete[] _min;
	_min = tmp2;
	capacity = NewCapacity;
}




