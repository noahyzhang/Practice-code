#if 0
#include"Stack.hpp"

int main()
{
	Stack<int> s;
	for(int i = 1;i<=9;++i)
		s.Push(i);
	s.Pop();
	int num = s.Min();
	num = s.Top();
	num = s.Size();
	return 0;
}
#endif