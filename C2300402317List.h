#pragma once
#include "CShape.h"
struct Node
{
	CShape* pShape = nullptr;
	Node* pNext = nullptr;
	
};
class C2300402317List
{
private:/*private 成员的使用，可以帮助实现“封装”——即隐藏
		类的实现细节，使得类的外部无法直接修改或访问这些细节。这有助于保证数据的安全性
		和完整性。*/
	Node* pHead;//链表的头节点指针，始终指向第一个节点
	int m_Count;
public:
	C2300402317List();//构造函数，在对象被创建时，自动调用，用于初始化
	~C2300402317List();//析构函数，在对像被销毁时自动调用，用于释放资源
	void PushHead(Node m_node);
	int Size();
	Node* Locat(int pos);//返回第pos个节点的地址
	void Del(int pos);//将第pos个节点的地址删掉
	void ClearAll();
	//void Insert(Node m_node, int pose);//传入一个节点，将此节点放在第pos的位置上



};

