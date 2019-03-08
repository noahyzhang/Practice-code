//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

#include<iostream>
#include<string>
#include<unordered_set>

int GetMaxLen(std::string& s)
{
	int resMax = -1;
	std::unordered_set<char> u_set;
	int i = 0, j = 0;
	int s_len = s.size();
	while (i < s_len && j < s_len)
	{
		if (u_set.count(s[j]) == 0)
		{
			u_set.insert(s[j++]);
			resMax = resMax > (j - i) ? resMax : (j - i);
		}
		else
			u_set.erase(s[i++]);	
	}
	return resMax;
}

int main()
{
	std::string s;
	std::cin >> s;
	int len = GetMaxLen(s);
	std::cout << len << std::endl;
	system("pause");
	return 0;
}