#if 0
#include"Stack_Correct.hpp"
#include<iostream>

int main()
{
	StackLegality<int> slg;
	for (int i = 1; i <= 5; ++i)
		slg.SetInArray(i);
	slg.SetOutAaary(3);
	slg.SetOutAaary(2);
	slg.SetOutAaary(5);
	slg.SetOutAaary(1);
	slg.SetOutAaary(4);

	bool res = slg.DecideLegality();
	if (res == true)
		std::cout << "合法" << std::endl;
	else
		std::cout << "不合法" << std::endl;
	return 0;
}

#endif