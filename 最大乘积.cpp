#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;
//һ�����������������ܳ���0

int GetMax(vector<int> arr)
{
	int maxPos = 0; //�õ���������
	int  maxSec = 0; //�õ��ڶ��������
	int  maxThi = 0; //�õ������������
	int minFu = 0;  //�õ���С����
	int minSec = 0;  //�õ��ڶ�С����
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
