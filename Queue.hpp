#if 0

#pragma once
//两个栈模拟一个队列
#include<stack>

template<typename T>
class Queue {
public:
	void Push(const T& data);
	void Pop();
	T& Front();
	T& Back();
	bool Empty();
	size_t Size();

private:
	std::stack<T> s1;
	std::stack<T> s2;
};

template<typename T>
void Queue<T>::Push(const T& data)
{
	s1.push(data);
}

template<typename T>
void Queue<T>::Pop()
{
	size_t len1 = s1.size();
	for (int i = 0; i < len1; ++i)
	{
		T num = s1.top();
		s1.pop();
		s2.push(num);
	}
	s2.pop();
	size_t len2 = s2.size();
	for (int i = 0; i < len2; ++i)
	{
		T num = s2.top();
		s2.pop();
		s1.push(num);
	}
}

template<typename T>
T& Queue<T>::Front()
{
	return s1.top();
}

template<typename T>
T& Queue<T>::Back()
{
	size_t len1 = s1.size();
	for (int i = 0; i < len1; ++i)
	{
		T num = s1.top();
		s1.pop();
		s2.push(num);
	}
	T res = s2.top();
	size_t len2 = s2.size();
	for (int i = 0; i < len2; ++i)
	{
		T tmp = s2.top();
		s2.pop();
		s1.push(tmp);
	}
	return res;
}

template<typename T>
bool Queue<T>::Empty()
{
	return s1.empty();
}

template<typename T>
size_t Queue<T>::Size()
{
	return s1.size();
}

#endif
