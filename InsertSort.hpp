#include<iostream>
#include<vector>

template<typename T>
void InsertSort(std::vector<T> &vec)
{
	int i = 0, j = 0;
	int len = vec.size();
	for (i = 1; i < len; ++i)
	{
		int tmp = vec[i];
		for (j = i; j > 0 && vec[j- 1] > tmp; --j)
		{
			vec[j] = vec[j - 1];
		}
		vec[j] = tmp;
	}
}

template<typename T>
void ShellSort(std::vector<T> &vec)
{
	int len = vec.size();
	int gap = len / 3 + 1;
	int i = 0, j = 0;
	while (gap > 1)
	{
		for (i = gap; i < len; ++i)
		{
			int pos = i - gap;
			int tmp = vec[i];
			while (pos > 0 && vec[pos] > tmp)
			{
				vec[]
			}
		}
		gap = gap / 3 + 1;
	}
}
void ShellSort(int *a, int len)     //插入排序的变形，通过预排序使得元素大致有序，再通过插入排序使得数组整体有序
{
	int gap = len;           //增量
	while (gap > 1)
	{
		gap = gap / 3 + 1;              //增量要减小，直到增减为1
		for (int index = gap; index < len; ++index)
		{
			int pos = index - gap;          //有序区的最后一个元素
			int tmp = a[index];
			while (pos > 0 && a[pos] > tmp)
			{
				a[pos + gap] = a[pos];
				pos -= gap;
			}
			a[pos + gap] = tmp;
		}
	}
}