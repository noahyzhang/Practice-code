
//有问题******************************************************************有问题
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//int _GetThiMax(std::vector<int>& vec, int i, int j, int k)
//{
//	if (vec[i] > vec[j])
//	{
//		if (vec[j] > vec[k])
//			return vec[j];
//		else if (vec[k] > vec[i])
//			return vec[i];
//		else
//			return vec[k];
//	}
//	else
//	{
//		if (vec[i] > vec[k])
//			return vec[i];
//		else if (vec[k] > vec[j])
//			return vec[j];
//		else
//			return vec[k];
//	}
//}
//
//int GetMax(std::vector<int>& vec, int n)
//{
//	std::vector<int> v_res;
//	int i = 0, j = 0, k = 0;
//	int len = vec.size();
//	for (i = 0; i < len; ++i)
//	{
//		for (j = i+1; j < len; ++j)
//		{
//			for (k = j+1; k < len; k++)
//			{
//				if (i != j && i != k && j != k)
//				{
//					int tmp = _GetThiMax(vec, i, j, k);
//					v_res.push_back(tmp);
//				}
//			}
//
//		}
//	}
//	int MaxRes = 0;
//	std::sort(v_res.begin(), v_res.end());
//	int count = v_res.size() - 1;
//	while (n--)
//	{
//		MaxRes += v_res[count];
//		count--;
//	}
//	return MaxRes;
//}
//
//int main()
//{
//	std::vector<int>  vec;
//	int n = 0;
//	int num = 0;
//	std::cin >> n;
//	for (int i = 0; i < 3 * n; ++i)
//	{
//		std::cin >> num;
//		vec.push_back(num);
//	}
//	int res = GetMax(vec, n);
//	std::cout << res;
//	return 0;
//}

//#include<iostream>
//#include<unordered_set>
//#include<string>
//
//
//int main()
//{
//	std::string str1;
//	std::string str2;
//	getline(std::cin, str1);
//	getline(std::cin, str2);
//	std::unordered_set<char> u_map;
//
//	for (int i = 0; i < str1.size(); ++i)
//	{	
//		char tmp = str1.at(i);
//		u_map.insert(tmp);
//	}
//	for (int i = 0; i < str2.size(); ++i)
//	{
//		if (u_map.count(str2[i]) > 0)
//		{
//			u_map.erase(str2[i]);
//		}
//	}
//	std::string res;
//	for (int i = 0; i < str1.size(); ++i)
//	{
//		if (u_map.count(str1[i]) > 0)
//			res.push_back(str1[i]);
//	}
//	for (int i = 0; i < res.size(); ++i)
//	{
//		std::cout << res[i];
//	}
//	return 0;
//}
//


//#include<iostream>
//#include<string>
//#include<vector>
//
//
//int main()
//{
//	int flag = 0;  // 0 代表没有空格, 1 代表有空格
//	std::string s1;
//	std::getline(std::cin, s1);
//	std::vector<std::string> vec;
//	std::string s2;
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		if (s1[i] != ' ')
//			s2.push_back(s1[i]);
//		else
//		{
//			s2.push_back(' ');
//			vec.push_back(s2);
//			s2.clear();
//		}
//	}
//	s2.push_back(' ');
//	vec.push_back(s2);
//	for (int i = vec.size()-1; i >= 1; --i)
//	{
//		std::cout << vec[i];
//	}
//	for (int i = 0; i < vec[0].size() - 1; ++i)
//		std::cout << vec[0][i];
//	return 0;
//}


//#include<iostream>
//#include<vector>
//
//int main()
//{
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> vec;
//	int num = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		std::cin >> num;
//		vec.push_back(num);
//	}
//	int count = 0;
//	int flag = 0;  //0代表相邻数字非递减，1代表相邻数字非递增,2代表数字相等
//	int preFlag = 0; // 保存上一次的flag
//	for (int i = 1; i < vec.size(); ++i)
//	{
//		int tmp1 = vec[i - 1];
//		int tmp2 = vec[i];
//		if (tmp1 > tmp2)
//		{
//			preFlag = flag;
//			flag = 0;
//		}
//		else if (tmp1 < tmp2)
//		{
//			preFlag = flag;
//			flag = 1;
//		}
//		else if (tmp1 == tmp2)
//		{
//			preFlag = flag;
//			flag = 2;
//		}
//
//		if ((preFlag == 1 && flag == 0) || (preFlag == 0 && flag == 1))
//			count++;
//	}
//	std::cout << count;
//	return 0;
//}


//#include<iostream>
//#include<string>
//
//int main()
//{
//	std::string str;
//	std::getline(std::cin, str);
//	int res = 0;
//	std::string sol;
//	sol.resize(str.size());
//	for (int i = 0; i < str.size(); ++i)
//	{
//		std::string tmp;
//		int count = 0;
//		while (str[i] >= '0' && str[i] <= '9')
//		{		
//			tmp.push_back(str[i]);
//			count++;
//			i++;
//
//		}
//		if (count > res)
//		{
//			res = count;
//			for (int i = 0; i < count; i++)
//			{
//				sol[i] = tmp[i];
//			}
//		}
//	}
//	std::cout << sol << std::endl;
//	return 0;
//}
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
	std::vector<int> vec;
	std::string str;
	getline(std::cin, str);
	for (int i = 0; i < str.size(); i += 2)
		vec.push_back(str[i] - '0');
	sort(vec.begin(), vec.end());

	int index = vec.size() / 2;
	std::cout << vec[index];

	//int res = 0;
	//int count = 0;
	//int num = vec[0];
	//for (int i = 1; i < vec.size(); ++i)
	//{
	//	int ret = 0;
	//	if (num == vec[i])
	//	{
	//		ret++;
	//		if (ret > count)
	//		{
	//			res = num;
	//			count = ret;
	//		}
	//	}
	//	else
	//		num = vec[i];
	//}

	return 0;
}

#endif
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n = 0, count = 0;
//	cin >> n >> count;
//	vector<int> vec(n+2);
//	vector<int> res(3 * n);
//	vector<int> res_i, res_j, res_k;
//	for (int i = 0; i < n; ++i)
//		cin >> vec[i];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			for (int k = j + 1; k < n; ++k)
//			{
//				int num = vec[i] + vec[j] + vec[k];
//				if (num == count)
//				{
//					res_i.push_back(i);
//					res_j.push_back(j);
//					res_k.push_back(k);
//					res.push_back(num);
//				}
//			}
//		}
//	}
//	if (res.empty())
//	{
//		cout << -1 << " " << -1 << " " << -1 << " ";
//		return 0;
//	}
//	int count1 = res_i[0] + res_j[0] + res_k[0];
//	int flag = 0;
//	for (int i = 1; i < res_i.size(); i++)
//	{
//		if (res_i[i] + res_j[i] + res_k[i] < count1)
//			flag = i;
//	}
//	cout << res_i[flag] << " " << res_j[flag] << " " << res_k[flag] << " ";
//	return 0;
//}
//#if 0
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> vec1(n);
//	for (int i = 0; i < n; i++)
//		cin >> vec1[i];
//	sort(vec1.begin(), vec1.end());
//	int mid = vec1.size() / 2;
//	int flag1 = 0, flag2 = 0;
//	if (vec1[mid] == 1)
//	{
//		for (int i = mid; i >= 0; i--)
//		{
//			if (vec1[i] == -1)
//			{
//				flag2 = i;
//				break;
//			}
//		}
//	}
//	else
//	{
//		for (int i = mid; i < vec1.size(); ++i)
//		{
//			if (vec1[i] == 1)
//			{
//				flag1 = i;
//				break;
//			}
//		}
//	}
//	int num1 = 0, num2 = 0, num3 = 0;
//	if (flag1 != 0)
//	{
//		num1 = vec1.size() - flag1;
//		num2 = flag1 - 1;
//		num3 = num1 > num2 ? (num2 - num1) : (num1 - num2);
//	}
//	else if (flag2 != 0)
//	{
//		num1 = vec1.size() - flag2 - 1;
//		num2 = flag1;
//		num3 = num1 > num2 ? (num2 - num1) : (num1 - num2);
//	}
//	cout << num3;
//	return 0;
//}
//
//#endif

#if 0
#include<iostream>
#include<string>

int main()
{
	std::string res, cur, input;
	std::cin >> input;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] >= '0' && input[i] <= '9')
			cur.push_back(input[i]);
		else
		{
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	std::cout << res;
	return 0;
}

#endif


#include<iostream>

using namespace std;
class A {
public:
	A(char* s)
	{
		cout << s << endl;
	}
	~A() {}
};

class B : virtual public A
{
public:
	B(char* s1, char* s2) :A(s1)
	{
		cout << s2 << endl;
	}
};

class C :virtual public A
{
public:
	C(char* s1, char* s2) :A(s1)
	{
		cout << s2 << endl;
	}
};

class D : public C, public B
{
public:
	D(char* s1, char* s2, char* s3, char* s4) : B(s1, s2), C(s1, s3)
	{
		cout << s4 << endl;
	}
};

int main()
{
	D *p = new D((char*)"char A", (char*)"char B", (char*)"char C", (char*)"char D");
	delete p;
	return 0;
}