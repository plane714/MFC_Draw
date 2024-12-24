#include "pch.h"
#include "C2300402317List.h"

C2300402317List::C2300402317List()//构造函数
{
	pHead = nullptr;
	m_Count = 0;
}

C2300402317List::~C2300402317List()//析构函数
{
}

void C2300402317List::PushHead(Node m_node)
{
	Node* p = new Node;//定义一个结构体指针，ew Node 创建了一个新的 Node 对象，并在堆内存
	//上为它分配空间。new Node 分配的 Node 对象一直存在，直到程序手动调用 delete p; 
	//释放它。这与在栈上分配的局部变量不同，堆上的变量不会在超出作用域后自动释放。
	*p = m_node;//利用指针p访问传进函数的“m_node”这个结构
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
	if (pHead == nullptr || pos < 0 || pos >= m_Count) return; // 检查链表是否为空和位置是否有效

	Node* temp;

	// 删除头节点
	if (pos == 0) {
		temp = pHead;
		pHead = pHead->pNext;
		delete temp;
	}
	else {
		// 找到要删除节点的前一个节点
		Node* current = pHead;
		for (int i = 0; i < pos - 1; i++) {
			current = current->pNext;//p=p->pNext，将p更新为指向下一个节点
		}

		// current->pNext 为要删除的节点
		temp = current->pNext;
		current->pNext = temp->pNext;
		delete temp;
	}

	// 更新节点计数
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
	if (pos < 0 || pos > m_Count) return;  // 无效位置检查

	Node* newNode = new Node;
	newNode->x = m_node.x; // 复制节点数据
	newNode->pNext = nullptr;

	// 插入到头部
	if (pos == 0) {
		newNode->pNext = pHead;
		pHead = newNode;
	}
	else {
		// 找到插入位置的前一个节点
		Node* current = pHead;
		for (int i = 0; i < pos - 1; i++) {
			current = current->pNext;
		}

		// 插入新节点到链表中
		newNode->pNext = current->pNext;
		current->pNext = newNode;
	}

	// 增加节点计数
	m_Count++;
}*/
