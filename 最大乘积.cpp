#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;
//一正两负、三正、不能出现0

int GetMax(vector<int> arr)
{
	int maxPos = 0; //拿到最大的正数
	int  maxSec = 0; //拿到第二大的正数
	int  maxThi = 0; //拿到第三大的正数
	int minFu = 0;  //拿到最小负数
	int minSec = 0;  //拿到第二小负数
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > 0)
		{
			if (arr[i] >= maxPos)
			{
				maxThi = maxSec;
				maxSec = maxPos;
				maxPos = arr[i];
			}
			else if (arr[i] >= maxSec)
			{
				maxThi = maxSec;
				maxSec = arr[i];
			}
			else if (arr[i] >= maxThi)
			{
				maxThi = arr[i];
			}
		}
		else if (arr[i] < 0)
		{
			if (arr[i] <= minFu)
			{
				minSec = minFu;
				minFu = arr[i];
			}
			else if (arr[i] <= minSec)
			{
				minSec = arr[i];
			}
		}
	}
	if (maxPos == 0)
		return 0;
	if (maxSec*maxThi >= minFu * minSec)
		return maxPos * maxSec*maxThi;
	else
		return maxPos * minFu*minSec;
}

//int main()
//{
//	vector<int> arr(10);
//	int i = 0;
//	string s;
//	getline(cin, s);
//
//	istringstream iss(s);
//	int num, res = 0;
//	while (iss >> num)
//	{
//		arr[res] = num;
//		res++;
//	}
//	int max = GetMax(arr);
//	cout << max << endl;
//	return 0;
//}
