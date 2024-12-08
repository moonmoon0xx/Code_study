#include <iostream>
#define Maxsize 100
#define ElemType int
typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;//ǰ��ǿ���������нڵ��ָ�����������ǿ���������ͷָ��;

bool InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return true;
}

bool DestroyList(LinkList& L)
{
	LinkList pre = L, p = L->next;//preΪp����һ���ڵ�
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	return true;
}

bool ClearList(LinkList& L)
{
	LinkList p, q;
	p = L->next;
	while(p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return 0;
}
int ListLength(LinkList L)
{
	LinkList p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int ListEmpty(LinkList L)
{
	return(L->next == NULL);
}

void DispList(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
		std::cout <<std::endl;
}

bool GetElem(LinkList L, int i, ElemType& e)
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (p)
	{
		e = p->data;
		return true;
	}
	return false;
}
//���ص�ַ

LNode* LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}

//�������
int LocateElem_i(LinkList L, ElemType e)
{
	LinkList p = L->next;
	for ( int i = 1;p ; i++)
	{
		if (p->data == e)
			return i;
		p = p->next;
	}
	return 0;
}

bool ListInsert(LinkList L, int i, ElemType e)
{
	int j = 0;
	LinkList p = L;//p����ָ��ͷ�ڵ�����׽ڵ�
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p)
	{
		LNode* s;
		s = new LNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
	return false;
}

bool ListDelete(LinkList L, int i, ElemType e)
{
	int j = 0;
	LinkList p = L;
	Lnode* q;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p)
	{
		q = p->next;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
	return false;
}

void CreatList0(LinkList& L, int n)
{
	L = new LNode;
	L->next = NULL;
	for ( int i = n; i > 0;i-- )
	{
		LNode* p;
		p= new LNode;
		std::cout << "please enter the data:" << i << "��" << " ";
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
	std::cout << std::endl;
}

void CreatList1(LinkList& L, ElemType a[], int n)
{
	LNode* s;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreatList2(LinkList& L, int n)
{
	LinkList r;
	L = new LNode;
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++)
	{
		LinkList p;
		p = new LNode;
		std::cout << "please enter the data:" << i << "��" << " ";
		std::cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

void main()
{
	LinkList L1;
	ElemType e,e1,x1,x2;
	x1 = 1;
	x2 = 2;
	/*1--��ʼ������L*/
	InitList(L1);
	/*2����ͷ�巨����5��Ԫ��*/
	CreatList0(L1, 5);
	DispList(L1);
	/*3����β�巨����5��Ԫ��*/
	CreatList2(L1, 5);
	/*4���ڴ�ͷ���ĵ�����L�в��ҵ�3�͵�6��Ԫ��*/
	DispList(L1);
	GetElem(L1, 3, e);
	std::cout << e << std::endl;
	if (GetElem(L1, 6, e1))
		std::cout << e1 << std::endl;
	else
		std::cout << "no the number" << std::endl;
	/*5���ֱ��ڴ�ͷ���ĵ�����L�е�2��6��Ԫ��֮ǰ����Ԫ��*/
	ListInsert(L1, 2, x1);
	DispList(L1);
	ListInsert(L1, 6, x2);
	DispList(L1);
	/*6���ڴ�ͷ���ĵ�����L�н���ɾ���������ֱ�ɾ����1��6��Ԫ��*/
	ListDelete(L1, 1, e);
	DispList(L1);
	ListDelete(L1, 6, e);
	/*7����ʾ���������е�ֵ*/
	DispList(L1);
}

