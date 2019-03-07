#include<iostream>
#include<vector>

template<typename T>
class BinaryHeap
{
public:
	BinaryHeap();
	BinaryHeap(std::vector<T> &v);
	void Insert(const T& data);
	void DeleteMin();                 //ɾ����СԪ��
	bool IsEmpty()const;                 //�ж϶��ǲ���Ϊ��
	const T& findMin()const;          //���Ҷ��е���СԪ��
protected:
	void buildHeap();                     //�ָ��ѵ�˳��
	void percolate(int hole);             //��hole��ʼ�»�����
protected:
	std::vector<T> _Heap;                   //�洢�Ķ���Ԫ�ص�����
	int _Size;                             //��Ƕ���Ԫ�صĸ���
};

template<typename T>
BinaryHeap<T>::BinaryHeap() : _Heap(0), _Size(0) { }

template<typename T>
BinaryHeap<T>::BinaryHeap(std::vector<T> &v) : _Heap(v.size()), _Size(v.size()) 
{
	for (size_t i = 0; i < v.size(); ++i)
		_Heap[i] = v[i];
	buildHeap();
}

template<typename T>
void BinaryHeap<T>::buildHeap()
{
	for (int i = (_Size - 2) / 2; i >= 0; --i)
	{
		percolate(i);
	}
}

template<typename T>
void BinaryHeap<T>::percolate(int hole)  //����������Ԫ�ض��ǲ���ͬ�ġ����ϵ��µ�
{
	int child = 0;
	T tmp = _Heap[hole];
	for (; hole * 2 + 1 < _Size; hole = child)
	{
		child = hole * 2 + 1;
		if (child + 1 < _Size && _Heap[child + 1] < _Heap[child])
			child++;
		if (tmp > _Heap[child])
			std::swap(_Heap[hole], _Heap[child]);
		else
			break;
	}
}

template<typename T>
void BinaryHeap<T>::Insert(const T& data)  //���µ���
{
	_Size++;
	_Heap.push_back(data);
	int i = _Size - 1;
	int parent = 0;
	for (; (i - 1) / 2 >= 0; i = (i-1)/2)
	{
		parent = (i - 1) / 2;
		if (_Heap[i] < _Heap[parent])
			std::swap(_Heap[i], _Heap[parent]);
		else
			break;
	}
}

template<typename T>
void BinaryHeap<T>::DeleteMin()                 //ɾ����СԪ��
{
	_Heap.erase(_Heap.begin());
	int i = 0;
	percolate(i);
}

template<typename T>
bool BinaryHeap<T>::IsEmpty()const                 //�ж϶��ǲ���Ϊ��
{
	return 0 == _Size;
}

template<typename T>
const T& BinaryHeap<T>::findMin()const          //���Ҷ��е���СԪ��
{
	return _Heap[0];
}