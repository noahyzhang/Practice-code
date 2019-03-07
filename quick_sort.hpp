#include<iostream>
#include<vector>
#include<ctime>

using namespace std;
//
//template<typename T>
//int _QuickSort(std::vector<T> &vec, int left, int right)
//{
//	int tmp = vec[left];
//	int i = left + 1, j = right;
//	while (true)
//	{
//		while (i <= j && vec[i] <= tmp)
//			i++;
//		while (j >= left + 1 && vec[j] >= tmp)
//			j--;
//		if (i > j)
//			break;
//		std::swap(vec[i], vec[j]);
//		i++, j--;
//	}
//	if(left != j)
//		std::swap(vec[left], vec[j]);
//	return j; 
//}
//
//template<typename T>
//void QuickSort(std::vector<T> &vec, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	int div = _QuickSort(vec, begin, end);
//	QuickSort(vec, begin, div - 1);
//	QuickSort(vec, div + 1, end);
//}
//
template<typename T>
void PrintArr(std::vector<T> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

#if 0
template <typename T>
int _partition2(T arr[], int l, int r) {

	//swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int i = l + 1, j = r;
	while (true) {
		while (i <= r && arr[i] < v)
			i++;

		while (j >= l + 1 && arr[j] > v)
			j--;

		if (i > j)
			break;

		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l], arr[j]);

	return j;
}

template <typename T>
void _quickSort(T arr[], int l, int r) {

	    if( l >= r )
	        return;
	/*if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}*/

	int p = _partition2(arr, l, r);
	_quickSort(arr, l, p - 1);
	_quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {

	srand(time(NULL));
	_quickSort(arr, 0, n - 1);
}
#endif


//int PartSort(int *a, int begin, int end)
//{
//	int left = begin;
//	int right = end;
//	while (left < right)
//	{
//		while (left < right&&a[left] <= a[end])     // 找到一个大于基准值的值
//		{
//			left++;
//		}
//		while (left < right&&a[right] >= a[end])    // 找到一个小于基准值的值
//		{
//			right--;
//		}
//		if (left < right)
//			std::swap(a[left], a[right]);
//	}
//	std::swap(a[left], a[end]);
//	return left;
//}
//
////再使用一个QuickSort函数，对划分后的得到的子序列进行递归处理。
////[begin,end]
//void QuickSort(int *a, int begin, int end)
//{
//	int div = PartSort(a, begin, end);
//	if (div - 1 > begin)                 //这个区间的元素个数大于一个的时候就要在进行划分排序
//		QuickSort(a, begin, div - 1);
//	if (div + 1 < end)
//		QuickSort(a, div + 1, end);
//}

#if 0   //一般方法
template<typename T>
int Partion(std::vector<T> &vec, int left, int right)
{
	T tmp = vec[left];
	int i = left + 1, j = right;
	while (i < j)
	{
		while (i <= j && vec[i] < tmp)
			i++;
		while (j >= i && vec[j] > tmp)
			j--;
		if (i < j)
			std::swap(vec[i], vec[j]);
	}
	if(vec[left] > vec[j])
		std::swap(vec[left], vec[j]);
	return j;
}

template<typename T>
void _QuickSort(std::vector<T> &vec, int start, int end)
{
	if (start >= end)
		return;
	int div = Partion(vec, start, end);
	_QuickSort(vec, start, div - 1);
	_QuickSort(vec, div + 1, end);
}

template<typename T>
void QuickSort(std::vector<T> &vec)
{
	if (vec.size() == 0)
		return;
	_QuickSort(vec, 0, vec.size() - 1);
}
#endif

#if 0
//填坑法
template<typename T>
int Partion2(std::vector<T> &vec, int left, int right)
{
	T tmp = vec[left];
	int i = left, j = right;
	while (1)
	{
		while (j > i && vec[j] >= tmp)
			j--;
		if (vec[j] < tmp)
			vec[i] = vec[j];
		while (i < j &&vec[i] <= tmp)
			i++;
		if (vec[i] > tmp)
			vec[j] = vec[i];
		if (i >= j)
			break;
	}
	vec[i] = tmp;
	return i;
}
#endif

#if 0
//前后指针法
template<typename T>
int Partion3(std::vector<T> &vec, int left, int right)
{
	int cur = left;
	int pre = cur - 1;

	while (cur < right)
	{
		if (vec[cur] < vec[right])
		{
			pre++;
			if (pre != cur)
				std::swap(vec[pre], vec[cur]);
		}
		cur++;
	}
	pre++;
	std::swap(vec[pre], vec[right]);
	return pre;
}

template<typename T>
void _QuickSort(std::vector<T> &vec, int start, int end)
{
	if (start >= end)
		return;
	int div = Partion3(vec, start, end);
	_QuickSort(vec, start, div - 1);
	_QuickSort(vec, div + 1, end);
}

template<typename T>
void QuickSort(std::vector<T> &vec)
{
	if (vec.size() == 0)
		return;
	_QuickSort(vec, 0, vec.size() - 1);
}

#endif