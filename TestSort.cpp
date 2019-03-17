#if 0
#include"quick_sort.hpp"
#include"merge_sort.hpp"
#include"HeapSort.hpp"
#include"InsertSort.hpp"

int main()
{
	std::vector<int> vec;
	//vec.push_back(9);
	//vec.push_back(8);
	//vec.push_back(7);
	//vec.push_back(6);
	//vec.push_back(5);
	//vec.push_back(4);
	//vec.push_back(3);
	//vec.push_back(2);
	//vec.push_back(1);
	//PrintArr(vec);
	//QuickSort(vec, 0, 8);
	//PrintArr(vec);

	//int arr[10];
	//srand(time(NULL));
	//for (int i = 0; i < 10; i++)
	//{
	//	int num = rand() % 100 + 1;
	//	arr[i] = num;
	//}
	//quickSort(arr, 10);

	/*int arr[] = { 9,8,7,6,5,4,3,2,1 };
	QuickSort(arr, 0, 8);
	for (int i = 0; i < 9; i++)
		std::cout << arr[i] << " ";*/
#if 0
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int num = rand() % 100 + 1;
		vec.push_back(num);
	}
	PrintArr(vec);
	QuickSort(vec);
	PrintArr(vec);
#endif

	//srand(time(NULL));
	//for (int i = 0; i < 10; ++i)
	//{
	//	int num = rand() % 100 + 1;
	//	vec.push_back(num);
	//}
	//PrintArr(vec);
	//MergeSort(vec);
	//PrintArr(vec);

	//int arr[10] = { 0 };
	//srand(time(NULL));
	//for (int i = 0; i < 10; ++i)
	//	arr[i] = rand() % 100 + 1;
	//MergeSort(arr, 0, 9);

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 100 + 1;
		vec.push_back(num);
	}
	//HeapSort(vec);
	InsertSort(vec);
	return 0;
}

#endif 