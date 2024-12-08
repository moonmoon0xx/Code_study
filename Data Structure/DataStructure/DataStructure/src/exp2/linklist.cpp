#include <iostream>
#define Maxsize 100
#define ElemType int
typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;//前者强调单链表中节点的指针变量、后者强调单链表的头指针;

bool InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return true;
}

bool DestroyList(LinkList& L)
{
	LinkList pre = L, p = L->next;//pre为p的上一个节点
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
//返回地址

LNode* LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}

//返回序号
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
	LinkList p = L;//p这里指向头节点而非首节点
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
		std::cout << "please enter the data:" << i << "：" << " ";
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
		std::cout << "please enter the data:" << i << "：" << " ";
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
	/*1--初始化链表L*/
	InitList(L1);
	/*2—用头插法插入5个元素*/
	CreatList0(L1, 5);
	DispList(L1);
	/*3—用尾插法插入5个元素*/
	CreatList2(L1, 5);
	/*4—在带头结点的单链表L中查找第3和第6个元素*/
	DispList(L1);
	GetElem(L1, 3, e);
	std::cout << e << std::endl;
	if (GetElem(L1, 6, e1))
		std::cout << e1 << std::endl;
	else
		std::cout << "no the number" << std::endl;
	/*5—分别在带头结点的单链表L中第2和6个元素之前插入元素*/
	ListInsert(L1, 2, x1);
	DispList(L1);
	ListInsert(L1, 6, x2);
	DispList(L1);
	/*6—在带头结点的单链表L中进行删除操作，分别删除第1和6个元素*/
	ListDelete(L1, 1, e);
	DispList(L1);
	ListDelete(L1, 6, e);
	/*7—显示链表中所有的值*/
	DispList(L1);
}

