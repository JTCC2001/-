#include <iostream>
using namespace std;
// ctrl shift A 重排版
#define MAXSIZE 20
#define ElementType int

// 线性表->链表中结点Node的定义
struct Node
{
	ElementType data;
	Node *next;
};
//typedef Node* LinkList; // LinkList就是指向Node的指针。这两种写法一样
typedef Node *LinkList;
// 定义链表时候用LinkList，定义结点指针时用Node *p，虽然两者是一个意思
// 默认我创建的链表都带有头结点

// 链表的初始化(创建的是头指针，用头指针的名字作为链表的名字)
// 傻杯，头指针指向头结点，意思就是头指针就是头结点的地址啊
// 初始化就是给头结点分配地址，这个地址就是头指针
bool LinkListInit(LinkList &L) // LinkList &L等价于 Lnode *&L，Lnode *&L是一个指向指针的引用
{
	L = new Node; // 输入LinList L是头指针，指向头结点或首元结点
	L->next = nullptr;
	return 1;
}

// 头插法创建单向链表：新来的node放在前部，L -> new node -> old node
void LinkListCreateHead(LinkList &L, int n) // size_t是任何对象能达到的最大长度，是个无符号值
{
	for (int i = 0; i < n; i++)
	{
		Node *p = new Node;
		cin >> p->data;
		p->next = L->next;
		L->next = p; // 头结点没有数据，有数据的是首元结点
	}
}

// 尾插法创建单向链表：新来的node放在尾部，L -> old node -> new node
void LinkListCreateTail(LinkList &L, int n) // size_t是任何对象能达到的最大长度，是个无符号值
{
	Node *t = L;
	for (int i = 0; i < n; i++)
	{
		Node *p = new Node;
		cin >> p->data;
		//p->next = t->next; // 一样的
		p->next = nullptr;
		t->next = p; // 头结点没有数据，有数据的是首元结点
		t = t->next;
	}
}

// 判断链表是否为空
bool LinkListIsEmpty(LinkList &L)
{
	if (L->next) // 非空
	{
		return 0;
	}
	else
		return 1;
}

// 销毁链表：把除了头指针以外的地方都delete掉
bool LinkListDestroy(LinkList &L)
{
	if (L->next == nullptr)
	{
		cout << "EMPTY" << endl;
		return 0;
	}
	while (L) // 地址存在
	{
		Node *p = L->next;
		delete L;
		L = p;
	}
	return 1;
}

// 统计链表长度
int LinkListGetLength(LinkList &L)
{
	if (L->next == nullptr)
		return 0;
	Node *t = L;
	int cnt = 0;
	while (t->next != nullptr)
	{
		cnt++;
		t = t->next;
	}
	return cnt;

}

// 获取第i个元素的值
bool LinkListGetElement(LinkList L, int i, ElementType &e)
{
	if (i < 1 || L->next == nullptr)
	{
		cout << "ERROR" << endl;
		return 0;
	}
	Node *t = L;
	for (int n = 0; n < i; n++)
	{
		if (!t->next) // t->next就是第i个元素的地址
		{
			cout << "NOT FOUND" << endl;
			return 0;
		}
		t = t->next;
	}
	e = t->data;
	return 1;
}

// **按值查找元素**
int LinkListLocateElement(LinkList L, ElementType e)
{
	if (!L->next)
	{
		cout << "EMPTY" << endl;
		return 0;
	}
	Node *t = L;
	int num = 0;
	while (t)
	{
		num++;
		if (t->next->data == e)
			return num;
		t = t->next;
	}
	return 0;

}

// **插入元素**
bool LinkListInsert(LinkList &L, int i, ElementType e)
{
	if (i < 1)
		return 0;
	Node *t = L;
	int j = 0;
	while (t && j < i - 1)
	{
		t = t->next;
		j++;
	}
	if (!t)
		return 0;

	LinkList insert = new Node;
	insert->data = e;
	insert->next = t->next;
	t->next = insert;
	return 1;
}

// **删除元素**
bool LinkListErase(LinkList &L, int i)
{
	if (i < 1)
		return 0;
	Node *t = L;
	int j = 0;
	while (t && j < i - 1)
	{
		t = t->next;
		j++;
	}
	if (!t)
		return 0;
	Node *erase = t->next;
	t->next = t->next->next;
	delete erase;
	return 1;

}

int main()
{
	LinkList L;
	LinkListInit(L);
	LinkListCreateTail(L, 5);

	LinkListInsert(L, 3, 123123);
	LinkListErase(L, 3);
	Node *p = L->next; // 首元结点
	for (;;)
	{
		cout << p->data << " ";
		if (p->next == nullptr)
			break;
		p = p->next;
	}
	

	//int num = LinkListLocateElement(L, 1);
	//cout << '\n' << "Location: " << num << endl;

	//		ElementType e = 999;
	//		LinkListGetElement(L, 3, e);
	//		cout << '\n' << "found element: " << e << endl;

	int cnt = LinkListGetLength(L); // 头结点不算在数量里
	cout << "Length: " << cnt << endl;
	//
	//	LinkListDestroy(L);
	//	if (!L)
	//		cout << "destroy succeess" << endl;
	system("pause");
}
