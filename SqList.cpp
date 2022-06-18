#include <iostream>
using namespace std;
// ctrl shift A 重排版
#define MAXSIZE 20
#define ElementType int

// 线性表->顺序表的定义
struct SqList
{
	ElementType *data; 
	int length;
};

// 线性表初始化：开辟空间，设定最大表长为MAXSIZE，现表长为0
bool SqListInit(SqList &L)
{
	L.data = new ElementType[MAXSIZE];
	if(!L.data) // 初始化错误
	{
		cout << "ERROR"<<endl;
		return 0;
	}
	L.length = 0;
	return 1;
}

// 线性表销毁
bool SqListDestroy(SqList &L)
{
	if(!L.data) // 没开辟空间没法销毁
	{
		cout << "EMPTY"<<endl;
		return 0;
	}
	delete L.data;
}

// 线性表的清空：表长为0时认定为空表
bool SqListClear(SqList &L)
{
	if(!L.data)
	{
		cout <<"NOT CREATED"<<endl;
		return 0;
	}
	L.length = 0;
	return 1;
}

// 判断是否为空：表长为0认定为空
bool SqListIsEmpty(SqList &L)
{
	return static_cast<bool>(L.length);
}

// 获取元素：返回第i个元素的值(i>0)
bool SqListGetElement(SqList L, int i, ElementType *e)
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

// 查找元素：查找是否有e元素，如果有则返回其下标，若没有则返回0
int SqListLocate(SqList &L, ElementType e)
{
	if (L.length == 0) // 空表
	{
		cout << "ERROR" << endl;
		return 0;
	}

	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			cout << "FOUND" << endl;
			return i + 1;
		}
	}
	return 0;
}
// 插入操作：在第i个位置插入新元素e(i>0)
bool SqListInsert(SqList &L, int p, ElementType e)
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
bool SqListDelete(SqList &L, int p, ElementType &e)
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
	SqListInsert(L, 3, 3);
	cout << "插入后" << endl;
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << endl;
	}
	int e = 0;
	SqListDelete(L, 3, e);
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << endl;
	}
	cout << e << endl;

	int index = 0;
	index = SqListLocate(L, 2);
	cout << "是否找到: " << index << endl;
}
