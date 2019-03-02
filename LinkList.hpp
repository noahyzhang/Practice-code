#if 0
#pragma once
#include<iostream>
#include<vector>
#include<cassert>

class ListNode {
public:
	int val;
	ListNode* next;
};


class LinkList{
private:
	ListNode* root;

	void Destory(ListNode* root);
	void print_end_front(ListNode* node);
	void QuickSort(ListNode* left,ListNode* right);
	void SwapNode(ListNode* left, ListNode* right);
	bool CheckCircle();
public:
	LinkList(std::vector<int> vec);
	~LinkList();

	void PrintEndToFront();   //��β��ͷ��ӡ������
	void DeleteNode(ListNode* node);  //ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
	void InsertNode(ListNode* node,int num);  //����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
	void JoseCir();           //������ʵ��Լɪ��(JosephCircle)
	void Reversal();          //���� / ��ת������
	void Sort();              //����������ð������&��������
	void Merge(ListNode* other_list);             //�ϲ�������������, �ϲ�����Ȼ����
	ListNode* FindBinNode();	      //���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
	ListNode* FindLastKNode(int k);      //���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
	void DeleteLastKNode(int k);         //ɾ������ĵ�����K�����
	ListNode* ListCircleStart();  //�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������
	bool CheckListInter(ListNode* other_list)  //�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
	int CheckListInterCircle();//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ�����
	//��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬
	//����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������
	LinkList* CopyList();
	void UnionSet();//��������������������ͬ�����ݡ�
};

#endif
