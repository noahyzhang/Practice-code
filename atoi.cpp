//1、如果输入的字符包含不是数字字符的字符？？？
//例如：“123adc4".
//针对这种情况，我们只要加上判断就行了，只要遇到不是数字字符的直接返回。
//
//2、如果在数字字符前面有正负号又该怎么办？？？
//例如：” - 123”、“ + 123”.
//针对这种情况，我们再加上判断，判断字符串的第一个字符是不是正负号，并用一个标记位flag记录正负。
//
//3、当输入的字符串前面几个字符都是空格又该怎么办？？？
//例：“ - 123”，“ + 123”.
//针对这种情况，库里面的atoi是将空格跳过再进行判断的，所以我们在一开始就用循环将空格跳过，
//注意这时候要是字符串里面全部是空格，则我们应该返回一个值，就返回0吧。
//
//4、当输入的字符串中没有数字时，我们应该返回什么呢？？？
//我们在这种情况下返回0.
//
//5、当字符串中的字符数字转化的整数太大，会有可能溢出？？？
//针对这种情况，我们需要做出一个判断，判断转化后的数字当它的范围在long的范围内。

//#include<iostream>
//#include<string>
//#include<vector>
//
//bool status = true; //状态，出现错误一律是false，正确就是true
//
//int my_atoi(std::string str)
//{
//	//如果遇到字符不是数字字符、或者字符前有空格都返回错误
//	//如果输入的字符串中没有数字，也给他返回错误
//	//如果要转换的字符串过大，可能会溢出，溢出的话也给他返回错误
//	int flag = 1; //标记正负,  -1 代表负数  1 代表正数
//	int i = 0; //遍历str的下标
//	std::vector<int> vec;
//	if (str.empty())
//	{
//		status = false;
//		return 0;
//	}
//	if (!((str[0] >= '0' && str[0] <= '9') || (str[0] == '+') || (str[0] == '-')))
//	{
//		status = false;
//		return 0;
//	}
//	if (str[0] == '+')
//	{
//		flag = 1;
//		i = 1;
//	}
//	else if (str[0] == '-')
//	{
//		flag = -1;
//		i = 1;
//	}
//	for (; i < str.size(); ++i)
//	{
//		if (!(str[i] >= '0' && str[i] <= '9'))
//		{
//			status = false;
//			return 0;
//		}
//		else
//		{
//			vec.push_back(str[i] - '0');
//		}
//	}
//	int len = vec.size() - 1;
//	int num = 1;
//	long int res = 0;
//	for (int i = len; i >= 0; --i)
//	{
//		res += vec[i] * num;
//		num *= 10;
//	}
//	res *= flag;
//	if (res >= INT_MAX || res <= INT_MIN)
//	{
//		status = false;
//		return 0;
//	}
//	return (int)res;
//}
//
//
//int main()
//{
//	std::string str;
//	std::cin >> str;
//	int res = my_atoi(str);
//	if (status == false)
//	{
//		std::cout << "输出有误，请重新输入" << std::endl;
//		return 0;
//	}
//	std::cout << res << std::endl;
//	return 0;
//}




