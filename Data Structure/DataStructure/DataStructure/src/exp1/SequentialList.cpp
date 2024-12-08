//实验1-2
#include <iostream>
#include <malloc.h>
#define Maxsize 50
typedef char ElemType;
//顺序表结构体
typedef struct
{
	ElemType data[Maxsize];
	int length;
}SqList;
//建立顺序表
void Creatlist(SqList*& L, ElemType a[], int n)
{
	L = (SqList*)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
}
//初始化线性表
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
//销毁线性表
void DestroyList(SqList*& L)
{
	free(L);
}
//判断线性表是否为空表
bool  ListEmpty(SqList* L)
{
	return(L->length == 0);
}
//求线性表的长度
int  ListLength(SqList* L)
{
	return(L->length);
}
//输出线性表
void DispList(SqList* L)
{
	for (int i = 0;i < L->length;i++)
		printf("%c  ", L->data[i]);
}
//求线性表中第i个元素值
bool GetElem(SqList* L, int i, ElemType& e)
{
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];
	return true;
}
//查找第一个值域为e的元素序号
int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length&& L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}
//插入第i元素
bool ListInsert(SqList*& L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1 || L->length == Maxsize)//1.i最低插入第一个 2.i最多插入到表尾 即 length+1 3.表要有空间**此时是逻辑位序
		return false;
	i--;//切换到物理位序
	for (int j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}
//删除第i个元素
bool ListDelete(SqList*& L, int i, ElemType& e)
{
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (int j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}
//int main()
//{
//	SqList* L;
//	/*char str[] = "ABCDE";*/
//	/*Creatlist(L1, str, 5);*/
//	ElemType e;
//	printf("顺序表的基本运算如下:\n");
//	printf("(1)初始化顺序表L\n");
//	InitList(L);
//	printf("(2)依次插人a,b,c,d,e元素\a\n");
//	ListInsert(L, 1, 'a');
//	ListInsert(L, 2, 'b');
//	ListInsert(L, 3, 'c');
//	ListInsert(L, 4, 'd');
//	ListInsert(L, 5, 'e');
//	printf("(3)输出顺序表L:\n");
//	DispList(L);
//	printf("\n(4)顺序表L长度:%d\n", ListLength(L));
//	printf("(5)顺序表L为%s\n", (ListEmpty(L) ? "空" : "非空"));
//	GetElem(L, 3, e);
//	printf("(6)顺序表L的第3个元素%c\n", e);
//	printf("(7)元素a的位置:%d\n", LocateElem(L, 'a'));
//	printf("(8)在第4个元素位置上插入f元素\n");
//	ListInsert(L, 4, 'f');
//	printf("(9)输出顺序表L:\n");
//	DispList(L);
//	printf("\n(10)删除L的第3个元素\n");
//	ListDelete(L, 3, e);
//	printf("(11)输出顺序表L:\n");
//	DispList(L);
//	printf("\n(12)释放顺序表\n");
//	DestroyList(L);
//	return 1;
//}