#if 0

#include"BinaryTree.hpp"

int main()
{
	BinaryTree<char> bt;
	std::vector<char> vec;
	vec.push_back('1');
	vec.push_back('2');
	vec.push_back('4');
	vec.push_back('#');
	vec.push_back('#');
	vec.push_back('5');
	vec.push_back('#');
	vec.push_back('#');
	vec.push_back('3');
	vec.push_back('#');
	vec.push_back('7');
	vec.push_back('#');
	vec.push_back('#');

	bt.CreateTree(vec, '#');
	//bt.PreOrderTree();
	//bt.PrintVector();

	//bt.InOrderTree();
	//bt.PrintVector();

	//bt.PostOrderTree();
	//bt.PrintVector();

	//bt.LevalTree();

	//bt.LevalTree2();

	size_t res = bt.GetFarthestDistance();
	std::cout << res << std::endl;

	char num1 = '5', num2 = '7';
	char ret = bt.GetAncestor(num1,num2);   //求两个结点的公共祖先节点
	std::cout << ret << std::endl;

	return 0;
}

#endif