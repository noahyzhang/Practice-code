#include<vector>

#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

void TestFunc() throw (int)
{
	throw 1.90;
}

int main()
{
	try
	{
		TestFunc();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	return 0;
}



#if 0
class A {
public:
	A() :m_iVal(0)
	{
		test();
	}
	virtual void func() 
	{
		std::cout << m_iVal << ' ';
	}
	void test()
	{
		func();
	}
public:
	int m_iVal;
};

class B :public A
{
public:
	B()
	{
		test();
	}
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << ' ';
	}
};

int main()
{
	A* p = new B;
	p->test();
	return 0;
}
#endif

#if 0

bool chkParenthesis(string A, int n) 
{
	// write code here
	int left = 0;
	int right = n - 1;
	while (left >= right)
	{
		if ((A[left] == '(' && A[right] == ')') || (A[left] == ')' && A[right] == '('))
		{
			left++;
			right--;
		}
		return false;
	}
	return true;
}

int main()
{
	string str = "(()())"
}
#endif

//迷宫地图
//#define VISITED 2
//int m, n, P; // 输入m，n，P
//int maze[11][11]; // 迷宫地图
//int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} }; // 左，右，上，下移动
//int cost[4] = { -1, -1, -3, 0 }; 
//int final_P = -200;
//struct mazePoint {
//	mazePoint(int _x, int _y) : x(_x), y(_y) {}
//	int x, y;
//};
//
//vector<mazePoint> pathStack;
//vector<mazePoint> minCostPath;
//
//void PrintPath(vector<mazePoint>& minPath)
//{
//	for (int i = 0; i < minPath.size(); i++)
//	{
//		cout << "[" << minPath[i].x << "," << minPath[i].y << "]";
//		if (i != minPath.size() - 1)
//			cout << ",";
//	}
//}
//
//void Search(int x, int y, int cur_P)
//{
//	pathStack.push_back(mazePoint(x, y));
//	maze[x][y] = VISITED;
//	if (x == 0 && y == m - 1 && cur_P >= 0)
//	{
//		if (cur_P != final_P)
//		{
//			final_P = cur_P;
//			minCostPath = pathStack;
//		}
//		pathStack.pop_back();
//		maze[x][y] = 1;
//		return;
//	}
//
//	if (cur_P > 0)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = dir[i][0] + x;
//			int ny = dir[i][1] + y;
//			int nP = cur_P + cost[i];
//			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1)
//				Search(nx, ny, nP);
//		}
//	}
//	pathStack.pop_back();
//	maze[x][y] = 1;
//}
//
//
//int main()
//{
//	cin >> n >> m >> P;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			cin >> maze[i][j];
//
//	Search(0, 0, P);
//	if (final_P != -200)
//		PrintPath(minCostPath);
//	else
//		cout << "Can not escape";
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class B0//基类BO声明
//{
//public://外部接口
//	virtual void display()//虚成员函数
//	{
//		cout << "B0::display0" << endl;
//	}
//};
//class B1 :public B0//公有派生
//{
//public:
//	void display() { cout << "B1::display0" << endl; }
//};
//class D1 : public B1//公有派生
//{
//public:
//	void display() { cout << "D1::display0" << endl; }
//};
//void fun(B0* ptr)//普通函数
//{
//	ptr->display();
//}
//int main()//主函数
//{
//	B0 *b0 = new B0;//声明基类对象和指针
//	B1 *b1 = new B1;//声明派生类对象
//	D1 *d1 = new D1;//声明派生类对象
//	fun(b0);//调用基类B0函数成员
//	fun(b1);//调用派生类B1函数成员
//	fun(d1);//调用派生类D1函数成员
//}



//int main()
//{
//	int a[5] = { 1,3,5,7,9 };
//	int *p = (int *)(&a + 1);
//	printf("%d, %d", *(a + 1),*(p - 1));
//}

//class A {
//public:
//	void test(float a) { cout << "1"; }
//};
//class B :public A {
//public:
//	void test(int b) { cout << "2"; }
//};
//
//int main()
//{
//	A *a = new A;
//	B *b = new B;
//	a->test(1);
//	a = b;
//	a->test(1.1);
//	//a.test(1.1);
//}

#if 0

void permutation(string& str, int left, int right)
{
	if (left == right)
	{
		for (int i = 0; i <= right; i++)
			cout << str[i] << " ";
		cout << endl;;
	}
	else
	{
		for (int i = left; i <= right; i++)
		{
			swap(str[i], str[left]);
			permutation(str, left + 1, right);
			swap(str[i], str[left]);
		}
	}
}

int main()
{
	string str;
	getline(cin, str);
	permutation(str, 0, str.size() - 1);
	return 0;
}
#endif


#if 0
bool Check(string str)
{
	stack<char> st;
	for (int i = 0; i < str.size(); i++)
		st.push(str[i]);
	for (int i = 0; i < str.size(); i++)
	{
		char c_st = st.top();
		st.pop();
		if (!((c_st == '(' && str[i] == ')') || (c_st == ')' && str[i] == '(')))
			return false;
	}
	return true;
}

string& Insert(string& str1, string& str2)
{

	str1.insert(str1.begin(), str2[i]);
}

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	string str3 = Insert(str1, str2);

}
#endif

#if 0
bool Compare(pair<unsigned long long int, unsigned long long int> p1, pair<unsigned long long int, unsigned long long int> p2)
{
	return p1.second > p2.second;
}

int main()
{
	unsigned long int n = 1;
	unsigned long long int d = 1;
	pair<unsigned long long int, unsigned long long int> pp;
	vector<pair<unsigned long long int, unsigned long long int>> vec(n);
	cin >> n >> d;
	for (unsigned long int i = 0; i < n; i++)
	{
		cin >> pp.first;
		cin >> pp.second;
		vec.push_back(pp);
	}
	sort(vec.begin(), vec.end(), Compare);

	unsigned long long int right = vec[0].first;
	unsigned long long int res = 0;
	unsigned long long int count = 0;
	unsigned long long int tmp = 0;
	for (unsigned long long int i = 0; i < n; i++)
	{
		for (unsigned long long int j = i+1; j < n; j++)
		{
			count = vec[i].first > vec[j].first ? vec[i].first - vec[j].first : vec[j].first - vec[i].first;
			if (count >= d)
			{
				tmp = vec[i].second + vec[j].second;
				break;
			}
		}
		if (tmp > res)
			res = tmp;
	}
	cout << res;
	return 0;
}

#endif

#if 0
int main()
{
	string str;
	getline(cin, str);
	int len = str.size();
	vector<bool> vec(27,false);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 97 ) //小写
		{
			if (vec[(str[i] - 'a')] == true)
			{	
				str.erase(i,1);
				i++;
				continue;
			}
			else
				vec[(str[i] - 'a')] = true;
		}
		else if (str[i] >= 65)  //大写
		{
			if (vec[(str[i] - 'A')] == true)
			{
				str.erase(i,1);
				i++;
				continue;
			}
			else
			{
				vec[(str[i] - 'A')] = true;
				str[i] += 32;
			}
		}
	}
	int index = 0;
	int i = 0;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == str[i + 1] + 1)
			break;
	}
	printf("%c", str[i]);
	/*for (int i = 0; i < 27; i++)
	{
		if (vec[i] == true && vec[i + 1] == true)
		{
			index = i;
			break;
		}
	}
	printf("%c", 'a' + index);*/
	return 0;
}

#endif
#if 0
bool Check(int a, int b)
{
	return a > b;
}

int main()
{
	int res = 0;
	int n = 0;
	cin >> n;
	vector<int> vec1(n);
	vector<int>  vec2(n);
	for (int i = 0; i < n; i++)
		cin >> vec1[i];
	for (int i = 0; i < n; i++)
		cin >> vec2[i];
	sort(vec2.begin(), vec2.end());  //将b数组进行排序
	sort(vec1.begin(), vec1.end(),Check);
	for (int i = 0; i < n; i++)
	{
		res += vec1[i] * vec2[i];
	}
	cout << res;
	return 0;
}

#endif