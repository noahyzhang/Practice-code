#include <string>
#include <iostream>


using namespace std;

string GetMul(string& s1, string& s2)
{
	int len1 = s1.size()-1;
	int len2 = s2.size()-1;
	string s3(len1 + len2 + 3, '0');
	s3[len1 + len2 + 2] = '\0';
	int len3 = 0, carry = 0;
	for (; len2 >= 0; --len2)
	{
		for (len1 = s1.size()-1; len1 >= 0; --len1)
		{
			int num = (s3[len1 + len2 + 1] - '0') + (s1[len1] - '0')*(s2[len2] - '0') + carry;
			s3[len1 + len2 + 1] = num % 10 + '0';
			carry = num / 10;
		}
		int m = 0;
		while (carry)
		{
			s3[len1 + len2 + 1 + (m--)] = carry % 10 + '0';
			carry /= 10;
		}
		len3 = len1 + len2 + 1 + m;
	}

	return s3.substr(len3 + 1);
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << GetMul(s1, s2) << endl;
	return 0;
}

