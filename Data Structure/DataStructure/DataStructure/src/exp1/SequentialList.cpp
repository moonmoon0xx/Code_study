//ʵ��1-2
#include <iostream>
#include <malloc.h>
#define Maxsize 50
typedef char ElemType;
//˳���ṹ��
typedef struct
{
	ElemType data[Maxsize];
	int length;
}SqList;
//����˳���
void Creatlist(SqList*& L, ElemType a[], int n)
{
	L = (SqList*)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
}
//��ʼ�����Ա�
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
//�������Ա�
void DestroyList(SqList*& L)
{
	free(L);
}
//�ж����Ա��Ƿ�Ϊ�ձ�
bool  ListEmpty(SqList* L)
{
	return(L->length == 0);
}
//�����Ա�ĳ���
int  ListLength(SqList* L)
{
	return(L->length);
}
//������Ա�
void DispList(SqList* L)
{
	for (int i = 0;i < L->length;i++)
		printf("%c  ", L->data[i]);
}
//�����Ա��е�i��Ԫ��ֵ
bool GetElem(SqList* L, int i, ElemType& e)
{
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];
	return true;
}
//���ҵ�һ��ֵ��Ϊe��Ԫ�����
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
//�����iԪ��
bool ListInsert(SqList*& L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1 || L->length == Maxsize)//1.i��Ͳ����һ�� 2.i�����뵽��β �� length+1 3.��Ҫ�пռ�**��ʱ���߼�λ��
		return false;
	i--;//�л�������λ��
	for (int j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}
//ɾ����i��Ԫ��
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
//	printf("˳���Ļ�����������:\n");
//	printf("(1)��ʼ��˳���L\n");
//	InitList(L);
//	printf("(2)���β���a,b,c,d,eԪ��\a\n");
//	ListInsert(L, 1, 'a');
//	ListInsert(L, 2, 'b');
//	ListInsert(L, 3, 'c');
//	ListInsert(L, 4, 'd');
//	ListInsert(L, 5, 'e');
//	printf("(3)���˳���L:\n");
//	DispList(L);
//	printf("\n(4)˳���L����:%d\n", ListLength(L));
//	printf("(5)˳���LΪ%s\n", (ListEmpty(L) ? "��" : "�ǿ�"));
//	GetElem(L, 3, e);
//	printf("(6)˳���L�ĵ�3��Ԫ��%c\n", e);
//	printf("(7)Ԫ��a��λ��:%d\n", LocateElem(L, 'a'));
//	printf("(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
//	ListInsert(L, 4, 'f');
//	printf("(9)���˳���L:\n");
//	DispList(L);
//	printf("\n(10)ɾ��L�ĵ�3��Ԫ��\n");
//	ListDelete(L, 3, e);
//	printf("(11)���˳���L:\n");
//	DispList(L);
//	printf("\n(12)�ͷ�˳���\n");
//	DestroyList(L);
//	return 1;
//}