#include <iostream>
using namespace std;
// ctrl shift A 重排版
#define MAXSIZE 20
#define ElementType int

// 线性表->顺序表的定义
struct SqList
{
	ElementType data[MAXSIZE]; // ElemType *data
	int length;
};

// 获取元素：返回第i个元素的值(i>0)
bool GetElement(SqList L, int i, ElementType *e)
{
	if (i > L.length || i < 1)
	{
		cout << "ERROR!" << endl;
		return 0;
	}
	*e = L.data[i - 1];
	return 1;
}

// 插入操作：在第i个位置插入新元素e(i>0)
bool ListInsert(SqList *L, int i, ElementType e)
{
	if (i > L->length || i < 1)
	{
		cout << "ERROR" << endl;
		return 0;
	}

}

int main()
{

}
