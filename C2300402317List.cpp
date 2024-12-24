#include "pch.h"
#include "C2300402317List.h"

C2300402317List::C2300402317List()//���캯��
{
	pHead = nullptr;
	m_Count = 0;
}

C2300402317List::~C2300402317List()//��������
{
}

void C2300402317List::PushHead(Node m_node)
{
	Node* p = new Node;//����һ���ṹ��ָ�룬ew Node ������һ���µ� Node ���󣬲��ڶ��ڴ�
	//��Ϊ������ռ䡣new Node ����� Node ����һֱ���ڣ�ֱ�������ֶ����� delete p; 
	//�ͷ�����������ջ�Ϸ���ľֲ�������ͬ�����ϵı��������ڳ�����������Զ��ͷš�
	*p = m_node;//����ָ��p���ʴ��������ġ�m_node������ṹ
	p->pNext = pHead;
	pHead = p;
	m_Count++;
}

int C2300402317List::Size()
{
	/*int s = 0;
	Node* p = pHead;
	while (p) {
		s++;
		p = p->pNext;
	}
	return s;*/
	return m_Count;
}

Node* C2300402317List::Locat(int pos)
{
	if (pos<=0||pos>m_Count)
	{
		return nullptr;
	}
	Node* p = pHead;
	for ( int i = 1; i<pos; i++)
	{
		p = p->pNext;
	}
	return p;
}

void C2300402317List::Del(int pos)
{
	if (pHead == nullptr || pos < 0 || pos >= m_Count) return; // ��������Ƿ�Ϊ�պ�λ���Ƿ���Ч

	Node* temp;

	// ɾ��ͷ�ڵ�
	if (pos == 0) {
		temp = pHead;
		pHead = pHead->pNext;
		delete temp;
	}
	else {
		// �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
		Node* current = pHead;
		for (int i = 0; i < pos - 1; i++) {
			current = current->pNext;//p=p->pNext����p����Ϊָ����һ���ڵ�
		}

		// current->pNext ΪҪɾ���Ľڵ�
		temp = current->pNext;
		current->pNext = temp->pNext;
		delete temp;
	}

	// ���½ڵ����
	m_Count--;

	}

	

void C2300402317List::ClearAll()
{
	Node* p = pHead;
	while (p) {
		Node* q = p;
		p=p->pNext;
		delete q;
	}
	m_Count = 0;
}

/*void C2300402317List::Insert(Node m_node, int pos)
{
	if (pos < 0 || pos > m_Count) return;  // ��Чλ�ü��

	Node* newNode = new Node;
	newNode->x = m_node.x; // ���ƽڵ�����
	newNode->pNext = nullptr;

	// ���뵽ͷ��
	if (pos == 0) {
		newNode->pNext = pHead;
		pHead = newNode;
	}
	else {
		// �ҵ�����λ�õ�ǰһ���ڵ�
		Node* current = pHead;
		for (int i = 0; i < pos - 1; i++) {
			current = current->pNext;
		}

		// �����½ڵ㵽������
		newNode->pNext = current->pNext;
		current->pNext = newNode;
	}

	// ���ӽڵ����
	m_Count++;
}*/
