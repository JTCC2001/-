#include <iostream>
using namespace std;
// ctrl shift A 重排版
#define MAXSIZE 20
#define ElementType int

// 线性表->顺序表的定义
class SqList
{
public:
	ElementType data[MAXSIZE]; // ElemType *data
	int length;
};

// 获取元素：返回第i个元素的值(i>0)
bool GetElement(SqList L, int i, ElementType *e)
{
	// 获取没有元素的位置时
	if (i > L.length || i < 1)
	{
		cout << "ERROR" << endl;
		return 0;
	}

	*e = L.data[i - 1]; // 第i个元素在数组的第i-1位置
	return 1;
}

// 插入操作：在第i个位置插入新元素e(i>0)
bool ListInsert(SqList &L, int p, ElementType e)
{
	// 表满
	if (L.length == MAXSIZE)
	{
		cout << "FULL" << endl;
		return 0;
	}
	// 插入位置不合理(不能在最后一个元素后面插入(那样不就是添加了嘛))
	if (p < 1 || p > MAXSIZE || p > L.length)
	{
		cout << "ERROR" << endl;
		return 0;
	}
	for (int i = L.length - 1; i >= p - 1; i--)
	{
		L.data[i + 1] = L.data[i];
	}

	L.data[p - 1] = e;
	L.length++;
	return 1;

}

// 删除操作：删除表中第i个元素，并用e返回其值
bool ListDelete(SqList &L, int p, ElementType &e)
{
	if (L.length == 0) // 空表
	{
		cout << "EMPTY" << endl;
		return 0;
	}
	if (p < 1 || p > L.length) // 插入位置不合理
	{
		cout << "ERROR" << endl;
		return 0;
	}

	e = L.data[p - 1];

	for (int i = p - 1; i < L.length; i++)
	{
		L.data[i] = L.data[i + 1];
	}

	L.length--;
	return 1;
}

int main()
{

	SqList L;
	L.length = 3;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 4;
	ListInsert(L, 3, 3);
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << endl;
	}
	int e = 0;
	ListDelete(L, 3, e);
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << endl;
	}
	cout << e << endl;
}
