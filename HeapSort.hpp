
#if 0
#include<iostream>
#include<vector>

template<typename T>
void AdjustDown(std::vector<T> &vec, int i, int len)
{
	int child = i * 2 + 1;
	
	while (child < len)
	{
		if (child + 1 < len && vec[child + 1] > vec[child])
			child++;
		if (vec[i] < vec[child])
		{
			std::swap(vec[i], vec[child]);
			i = child;
			child = child * 2 + 1;
		}
		else
			break;
	}
}

template<typename T>
void HeapSort(std::vector<T> &vec)
{
	int len = vec.size() - 1;
	//½¨¶Ñ
	for (int i = (len - 1) / 2; i >= 0; --i)
		AdjustDown(vec, i, len);

	//ÅÅÐò
	while (len >= 0)
	{
		std::swap(vec[0], vec[len]);
		len--;
		AdjustDown(vec, 0, len);
	}
}

#endif