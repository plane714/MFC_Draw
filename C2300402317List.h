#pragma once
#include "CShape.h"
struct Node
{
	CShape* pShape = nullptr;
	Node* pNext = nullptr;
	
};
class C2300402317List
{
private:/*private ��Ա��ʹ�ã����԰���ʵ�֡���װ������������
		���ʵ��ϸ�ڣ�ʹ������ⲿ�޷�ֱ���޸Ļ������Щϸ�ڡ��������ڱ�֤���ݵİ�ȫ��
		�������ԡ�*/
	Node* pHead;//�����ͷ�ڵ�ָ�룬ʼ��ָ���һ���ڵ�
	int m_Count;
public:
	C2300402317List();//���캯�����ڶ��󱻴���ʱ���Զ����ã����ڳ�ʼ��
	~C2300402317List();//�����������ڶ�������ʱ�Զ����ã������ͷ���Դ
	void PushHead(Node m_node);
	int Size();
	Node* Locat(int pos);//���ص�pos���ڵ�ĵ�ַ
	void Del(int pos);//����pos���ڵ�ĵ�ַɾ��
	void ClearAll();
	//void Insert(Node m_node, int pose);//����һ���ڵ㣬���˽ڵ���ڵ�pos��λ����



};

