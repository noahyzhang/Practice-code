#if 0

#pragma once
#include<vector>
#include<stack>

template<typename T>
class StackLegality
{
public:
	void SetInArray(const T& data);        //输入入栈序列
	void SetOutAaary(const T& data);       //输入出栈序列
	bool DecideLegality();

private:
	std::stack<T> s;
	std::vector<T> InArray;
	std::vector<T> OutArray;
};

template<typename T>
void StackLegality<T>::SetInArray(const T& data)
{
	InArray.push_back(data);
}

template<typename T>
void StackLegality<T>::SetOutAaary(const T& data)
{
	OutArray.push_back(data);
}

template<typename T>
bool StackLegality<T>::DecideLegality()
{
	for (int i = 0; i < InArray.size(); ++i)
	{
		s.push(InArray[i]);
	}
	if (InArray.size() != OutArray.size())
		return false;
	int i = 0, j = 0;
	size_t s_len = s.size();
	while (i < s_len)
	{
		T tmp = s.top();
		s.pop();
		if (tmp == OutArray[j])
			j++;		
		else
		{
			T sec_top = s.top();
			if (sec_top == OutArray[j])
			{
				s.pop();
				s.push(tmp);
				j++;
			}
			else
				break;
		}
		i++;
	}
	if (s.empty())
		return true;
	else
		return false;
}

#endif