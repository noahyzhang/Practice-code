#if 0
#include"Queue.hpp"
#include<iostream>

int main()
{
	Queue<int> q;
	for (int i = 1; i <= 10; ++i)
		q.Push(i);
	q.Pop();
	int front = q.Front();
	int back = q.Back();
	std::cout << front << std::endl << back << std::endl;
	return 0;

}

#endif