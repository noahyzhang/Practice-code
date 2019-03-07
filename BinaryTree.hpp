#pragma once
#include<stack>
#include<vector>
#include<queue>
#include<iostream>

template<typename T>
class Tree {
public:
	T _data;
	Tree<T>* _left;
	Tree<T>* _right;
public:
	Tree(T& data) 
	{
		this->_data = data;
		this->_left = nullptr;
		this->_right = nullptr;
	}
};

template<typename T>
class BinaryTree {
public:
	BinaryTree() {}
	~BinaryTree()
	{
		Destroy(root);
	}
	void CreateTree(std::vector<T>& vec,const T& invalid);
	void PreOrderTree();
	void InOrderTree();
	void PostOrderTree();
	void Destroy(Tree<T>* cur);
	void PrintVector();
	void LevalTree();   //层序遍历 
	void LevalTree2();  //层序遍历升级版（一层打印一行）
	size_t GetFarthestDistance();  //得到二叉树中两个结点的最远距离
	T GetAncestor(T& num1,T& num2);  //找两个节点的公共祖先节点
	Tree<T>* Find(T& num);
	

private:
	size_t _GetFarthestDistance(Tree<T>* cur, size_t distance);
	void _GetAncestor(std::vector<Tree<T>*>& vec1,std::vector<Tree<T>*>& vec2 ,T& num1, T& num2);
	Tree<T>* _Find(Tree<T>* cur, T& num);

private:
	Tree<T>* root;
	std::vector<T> v;

};


template<typename T>
void BinaryTree<T>::Destroy(Tree<T>* cur)
{
	if (cur->_left == nullptr && cur->_right == nullptr)
	{
		delete cur;
		cur = nullptr;
		return;
	}
	if (cur->_left != nullptr)
		return Destroy(cur->_left);
	if (cur->_right != nullptr)
		return Destroy(cur->_right);
}

template<typename T>
void BinaryTree<T>::CreateTree(std::vector<T>& vec,const T& invalid) // 先序创建
{
	Tree<T>* cur = nullptr;
	size_t index = 0;
	size_t len = vec.size();
	std::stack<Tree<T>*> st;
	while (index < len)
	{	
		while (index < len && vec[index] != invalid)
		{
			if (index == 0)
			{
				this->root = new Tree<T>(vec[index++]);
				cur = root;
			}
			else
			{
				cur->_left = new Tree<T>(vec[index++]);
				cur = cur->_left;
			}
			st.push(cur);
		}
		index++;
		if (!st.empty())
		{
			cur = st.top();
			st.pop();
		}
		if (index < len && vec[index] != invalid)
		{
			cur->_right = new Tree<T>(vec[index++]);
			cur = cur->_right;
			st.push(cur);
		}
	}
}

template<typename T>
void BinaryTree<T>::PreOrderTree()
{
	Tree<T>* cur = root;
	std::stack<Tree<T>*> st;
	if (root == nullptr) return;
	while (cur != nullptr || !st.empty())
	{
		while (cur != nullptr)
		{
			st.push(cur);
			v.push_back(cur->_data);
			cur = cur->_left;
		}
		Tree<T>* Top = nullptr;
		if (!st.empty())
		{
			Top = st.top();
			st.pop();
		}
		cur = Top->_right;
	}
}

template<typename T>
void BinaryTree<T>::InOrderTree()
{
	std::stack<Tree<T>*> st;
	Tree<T>* cur = root;
	while (cur != nullptr || !st.empty())
	{
		while (cur != nullptr)
		{
			st.push(cur);
			cur = cur->_left;
		}
		if (!st.empty())
		{
			Tree<T>* Top = st.top();
			v.push_back(Top->_data);
			st.pop();
			cur = Top->_right;
		}
	}
}

//试想一下，非递归遍历一棵二叉树无非三种状态，遍历左路，遍历右子树的根节点，出栈。只要我们用一个标记flag来标记这三个状态。
//flag = 1, 遍历左路，左路为空时将flag设置为2,否则将这个节点放到栈中。
//flag = 2, 遍历栈顶元素的右子树的根节点，若这个结点为空则flag = 3, 否则将这个遍历完这个结点后再将flag设置为1。
//flag = 3, 表明栈顶元素的左右子树已经遍历完毕，将栈顶元素出栈，flag 设置为2。

template<typename T>
void BinaryTree<T>::PostOrderTree()
{
	int flag = 1;
	std::stack<Tree<T>*> st;
	Tree<T>* cur = root;
	st.push(cur);
	while (!st.empty())
	{
		cur = st.top();
		if (flag == 1)
		{
			if (cur->_left == nullptr)
				flag = 2;
			else
			{
				cur = cur->_left;
				st.push(cur);
			}
		}
		else if (flag == 2)
		{
			if (cur->_right == nullptr)
				flag = 3;
			else
			{
				cur = cur->_right;
				st.push(cur);
				flag = 1;
			}
		}
		else if (flag == 3)
		{
			Tree<T>* Top = st.top();
			st.pop();
			v.push_back(Top->_data);
			while (!st.empty() && Top == st.top()->_right)
			{
				Top = st.top();
				v.push_back(Top->_data);
				st.pop();
			}
			flag = 2;
		}
	}
}

template<typename T>
void BinaryTree<T>::PrintVector()
{
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void BinaryTree<T>::LevalTree()
{
	if (root == nullptr)  return;
	std::queue<Tree<T>*> qu;
	Tree<T>* cur = root;
	qu.push(cur);
	while (!qu.empty())
	{
		Tree<T>* pBNode = nullptr;
		if (!qu.empty())
		{
			pBNode = qu.front();
			std::cout << pBNode->_data << " ";
			qu.pop();
		}
		if (pBNode->_left != nullptr)
			qu.push(pBNode->_left);
		if (pBNode->_right != nullptr)
			qu.push(pBNode->_right);
	}
}

template<typename T>
void BinaryTree<T>::LevalTree2()
{
	if (root == nullptr)  return;
	std::queue<Tree<T>*> qu;
	Tree<T>* last = root;   //上一行中最右边的结点
	Tree<T>* nlast = root;  //下一行中最右边的结点
	qu.push(root);
 	while (!qu.empty())
	{
		Tree<T>* cur = nullptr;
		if (!qu.empty())
		{
			cur = qu.front();
			qu.pop();
			std::cout << cur->_data << " ";
		}
		if (cur->_left != nullptr)
		{
			qu.push(cur->_left);
			nlast = cur->_left;
		}
		if (cur->_right != nullptr)
		{
			qu.push(cur->_right);
			nlast = cur->_right;
		}
		if (cur == last)
		{
			std::cout << std::endl;
			last = nlast;
		}
	}
}

template<typename T>
size_t BinaryTree<T>::_GetFarthestDistance(Tree<T>* cur,size_t distance)
{
	if (cur == nullptr)  return 0;
	size_t left = _GetFarthestDistance(cur->_left, distance);
	size_t right = _GetFarthestDistance(cur->_right, distance);
	if ((left + right) > distance)
		distance = left + right;
	return left > right ? left + 1 : right + 1;
}

template<typename T>
size_t BinaryTree<T>::GetFarthestDistance()
{
	Tree<T>* cur = root;
	size_t distance = 0;
 	distance = _GetFarthestDistance(cur, distance);
	return distance;
}


template<typename T>
Tree<T>* BinaryTree<T>::Find(T& num)
{
	static Tree<T>* cur = nullptr;
	cur = root;
	std::queue<Tree<T>*> q;
	q.push(cur);
	while (!q.empty() || cur != nullptr)
	{
		if(!q.empty())
		{
			cur = q.front();
			q.pop();
			if (cur->_data == num)
				break;
		}	
		if (cur->_left != nullptr)
			q.push(cur->_left);
		if (cur->_right != nullptr)
			q.push(cur->_right);
	}
	return cur;
}
 
//有问题********************************************************
//template<typename T>
//void BinaryTree<T>::_GetAncestor(std::vector<Tree<T>*>& vec1,std::vector<Tree<T>*>& vec2,T& num1, T& num2)
//{
//	Tree<T>* cur = root;
//	while (cur != nullptr)
//	{
//		if (num1 == cur->_data)
//		{
//			vec1.push_back(cur);
//			break;
//		}
//		else if (num1 > cur->_data)
//		{
//			vec1.push_back(cur);
//			cur = cur->_right;
//		}
//		else if (num1 < cur->_data)
//		{
//			vec1.push_back(cur);
//			cur = cur->_left;
//		}
//	}
//
//	cur = root;
//	while (cur != nullptr)
//	{
//		if (num2 == cur->_data)
//		{
//			vec2.push_back(cur);
//			break;
//		}
//		else if (num2 > cur->_data)
//		{
//			vec2.push_back(cur);
//			cur = cur->_right;
//		}
//		else if (num2 < cur->_data)
//		{
//			vec2.push_back(cur);
//			cur = cur->_left;
//		}
//	}
//}


//保存两个结点的路劲在数组中，然后拿到两个数组来进行比较，
//如果遇到不相同的，那么这个不相同的上一个节点就是他们的公共祖先节点
template<typename T>
T BinaryTree<T>::GetAncestor(T& num1, T& num2)  //求这个节点的公共祖先节点
{
	Tree<T>* Pnum1 = Find(num1);
	if (Pnum1 == nullptr)  return -1;  //如果有节点不存在，那么就返回-1，需要保证节点没有-1
	Tree<T>* Pnum2 = Find(num2);
	if (Pnum2 == nullptr)  return -1;  //如果有节点不存在，那么就返回-1，需要保证节点没有-1
	Tree<T>* cur = root;
	std::vector<Tree<T>*> vec1, vec2;
	_GetAncestor(vec1,vec2, num1, num2);

	size_t i = 0;
	size_t len1 = vec1.size();
	size_t len2 = vec2.size();
	while (i < len1 && i < len2)
	{
		if (vec1[i] == vec2[i])
			i++;
		else
			break;
	}
	return vec1[i - 1]->_data;
}