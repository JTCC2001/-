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
// 因为链表是 头指针+(头结点)+一堆结点，要访问这个链表，首先要通过头指针
// 头指针只是一个指向结点的指针，所以有下面的typedef
typedef Node *LinkList; // 定义LinkList

// 链表的初始化
bool LinkListInit(LinkList &L)
{
    L = new Node;
    L->next = nullptr;
    return 1;
}


// 获取元素：获取第i个元素的数据
bool NodeGetElement(LinkList L,int i,ElementType &e)
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