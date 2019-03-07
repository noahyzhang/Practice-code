#if 0
#include"Heap.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(4);
	vec.push_back(0);
	vec.push_back(9);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(11);
	vec.push_back(16);
	BinaryHeap<int> heap(vec);
	int num = heap.findMin();
	heap.Insert(-1);
	heap.DeleteMin();

	return 0;
}

#endif
