#include<iostream>
#include<vector>

#if 0
template<typename T>
void Partion(std::vector<T> &vec, int left1, int right1, int left2, int right2,std::vector<T> &vec2)
{
	int index = left1;
	while (left1 <= right1 && left2 <= right2)
	{
		if (vec[left1] < vec[left2])
			vec2[index++] = vec[left1++];
		else
			vec2[index++] = vec[left2++];
	}
	while (left1 <= right1)
		vec2[index++] = vec[left1++];
	while (left2 <= right2)
		vec2[index++] = vec[left2++];

	for (int i = 0; i < index; ++i)
		vec[i] = vec2[i];
}

template<typename T>
void _MergeSort(std::vector<T> &vec, int start, int end, std::vector<T> &vec2)
{
	if (start >= end)
		return;
	int mid = ((end - start) >> 1) + start;
	if (mid > start)
		_MergeSort(vec, start, mid, vec2);
	if (mid - 1 < end)
		_MergeSort(vec, mid + 1, end, vec2);
	Partion(vec, start, mid, mid + 1, end, vec2);
}

template<typename T>
void MergeSort(std::vector<T> &vec)
{
	int len = vec.size();
	std::vector<T> vec2(vec.size(),0);
	_MergeSort(vec,0, len - 1,vec2);
}

void _MergeSort(int *a, int begin, int end, int *tmp)
{
	int mid = ((begin^end) >> 1) + (begin&end);
	if (mid > begin)
		_MergeSort(a, begin, mid, tmp);
	if (mid + 1 < end)
		_MergeSort(a, mid + 1, end, tmp);
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)             //先将归并时的元素放到辅助数组中，如果放到原数组的话有可能会覆盖掉其他元素产生错误
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	while (begin <= end)                                     //将辅助数组中的元素再拷贝到原数组中
	{
		a[begin] = tmp[begin++];
	}
}
void MergeSort(int *a, int begin, int end)
{
	int *tmp = new int[end - begin + 1];
	_MergeSort(a, begin, end, tmp);
	delete[] tmp;
}
#endif

#if 0

template<typename T>
void _Merge(std::vector<T> &vec, int start, int end, int mid)
{
	std::vector<T> vec2(vec.size(), 0);
	int index = start;
	int left1 = start, right1 = mid, left2 = mid + 1, right2 = end;
	while (left1 <= right1 && left2 <= right2)
	{
		if (vec[left1] < vec[left2])
			vec2[index++] = vec[left1++];
		else
			vec2[index++] = vec[left2++];
	}
	while (left1 <= right1)
		vec2[index++] = vec[left1++];
	while (left2 <= right2)
		vec2[index++] = vec[left2++];
	for (int i = start; i < index; ++i)
		vec[i] = vec2[i];
}

template<typename T>
void _MergeSort(std::vector<T> &vec, int start, int end)
{
	if (start >= end)
		return;
	int mid = ((end - start) >> 1) + start;
	_MergeSort(vec, start, mid);
	_MergeSort(vec, mid + 1, end);
	_Merge(vec, start, end, mid);
}

template<typename T>
void MergeSort(std::vector<T> &vec)
{
	int len = vec.size();
	_MergeSort(vec, 0, len - 1);
}
#endif