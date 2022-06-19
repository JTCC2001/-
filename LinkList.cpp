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

// 链表的初始化(用头指针的名字作为链表的名字)
bool LinkListInit(LinkList &L) // LinkList &L等价于 Lnode *&L，Lnode *&L是一个指向指针的引用
{
    L = new Node; // 输入LinList L是头指针，指向头结点或首元结点
    L->next = nullptr;
    return 1;
}

// 头插法创建单向链表：新来的node放在前部，L -> new node -> old node
void LinkListCreateHead(LinkList &L, size_t n) // size_t是任何对象能达到的最大长度，是个无符号值
{
    for(int i = 0;i<n;i++)
    {
        Node *p = new Node;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

// 尾插法创建单向链表：新来的node放在尾部，L -> old node -> new node
void LinkListCreateHead(LinkList &L, size_t n) // size_t是任何对象能达到的最大长度，是个无符号值
{
    Node *t = L;
    for(int i = 0;i<n;i++)
    {
        Node *p = new Node;
        cin >> p->data;
        p->next = nullptr; // p.next = r.next 
        t->next = p;
        t=t->next;
    }
}

// 获取元素：获取第i个元素的数据
bool LinkListGetElement(LinkList L,int i,ElementType &e)
{
	if(i<1)
	{
		cout <<"ERROR"<<endl;
		return 0;
	}
	if(!L->next)
	{
		cout <<"EMPTY"<<endl;
		return 0;
	}

	LinkList t;
	t = L->next; // 指向首元结点
	for(int n = 0;n<i-1;n++)
	{
		if(!t->next)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		t = t->next;
	}
	e = t->data;
	return 1;
}

int main()
{

}