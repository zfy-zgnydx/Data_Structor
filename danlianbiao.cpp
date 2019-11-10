//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//存储结构
typedef struct LNode  {
	ElemType data;
	struct LNode *next;
}LNode;
typedef LNode *LinkList;
//StudybarCommentEnd
void InitList_L(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
}
void CreateList_L(LinkList &L)
{
	int n;
	scanf("%d",&n);
	LinkList p=L;
	LinkList t=new LNode;
	t->next=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t->data);
		p->next=t;
		p=p->next;
		t=new LNode;
		t->next=NULL;
	}
}
void GetElem_L(LinkList L,int i,ElemType &e)
{
	int j=1;
	LinkList temp=L->next;
	while(temp!=NULL&&(j<i))
	{
		temp=temp->next;
		j++;
	}
	if(temp==NULL||(j>i)) 
	{
	printf("Position Error!\n");
	exit(0);
    }
	else 
	{
	    e=temp->data;
	    printf("The element at position %d is %d\n",i,e);
	}
}
bool LocateElem_L(LinkList L,ElemType e)
{
	int i=1;
	LinkList p=L->next;
	while(p&&(p->data!=e))
	{
		p=p->next;
		i++;
	}
	if(!p) {
	printf("Element %d is not exist\n",e);
	return 0;
    }
	else {
	printf("The position of element %d is %d\n",e,i);
	return 1;
    }
}
void PreElem_L(LinkList L,ElemType e)
{
	int i=1;
	int x;
	LinkList p=L->next;
	while(p->next!=NULL&&(p->next->data!=e))
	{
		p=p->next;
		i++;
	}
	if(p->next==NULL||i==1) 
	{
	printf("The element %d's previous element is not exist\n",e);
    }
	else
	{ 
	x=p->data;
	printf("The element %d's previous element is %d\n",e,x);
    }
}
void NextElem_L(LinkList L,ElemType e)
{
    int x;
	LinkList p=L->next;
	while((p->data!=e)&&p->next!=NULL)
	{
		p=p->next;
	}
	
	if(p->next==NULL)
	{
		printf("The element %d's next element is not exist\n",e);
	}
	else
	{
	    p=p->next;
	    x=p->data;
	    printf("The element %d's next element is %d\n",e,x);
    }
}
bool ListDelete_L(LinkList &L,int i,ElemType &e)
{
	if(i<1)
		{
			printf("Position Error!\n");
			return 0;
		}
	LinkList p=L->next;
	for(int j=1;j<i-1 && p!=NULL;j++)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("Position Error!\n");
			return 0;
		}
	}
	LinkList t;
	if(i!=1)
	{
	    t=p->next;
		e=t->data;
		p->next=p->next->next;
		delete t;
	}
	else
	{
		t=L;
		e=t->next->data;
		t->next=p->next;
		delete p;
		
	}
	
	
	
	return 1;
	//printf("Deleted element: %d",e);
}
bool ListInsert_L(LinkList &L,int i,ElemType &e)
{
	if(i<1)
		{
			printf("Position Error!\n");
			return 0;
		}
    LinkList p=L->next;
    if(i==1)
    {
    	LinkList q=L;
    	LinkList temp=new LNode;
    	temp->data=e;
    	temp->next=p;
    	q->next=temp;
    	return 1;
	}
	for(int j=1;j<i-1 && p;j++)
	{
		p=p->next;
		if(p->next==NULL && i-1-j!=1)
		{
			printf("Position Error!\n");
			return 0;
		}
	}
	if(p->next==NULL)
		{
			LinkList t=new LNode;
			t->data=e;
			p->next=t;
			t->next=NULL;
		}
	else
	{
	LinkList t=p->next;
	LinkList insert=new LNode;
	insert->data=e;
	insert->next=p->next;
	p->next=insert;
    }
	return 1;
	//printf("Deleted element: %d",e);
}
void TraverseList_L(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void DestroyList_L(LinkList L)
{
}
//StudybarCommentBegin
int main()  {
	LinkList L;
	ElemType e;
	int i;

	InitList_L(L);
	CreateList_L(L);
	printf("CreateList_L: ");
	TraverseList_L(L);
	scanf("%d",&i);			//待取元素位置
	GetElem_L(L,i,e);
	scanf("%d",&e);			//待查找的元素
	if(LocateElem_L(L,e))  {
		PreElem_L(L,e);
		NextElem_L(L,e);
	}
	scanf("%d%d",&i,&e);		//插入位置和元素
	if(ListInsert_L(L,i,e))  {
		printf("LinkList after Insert: ");
		TraverseList_L(L);
	}
	scanf("%d",&i);			//删除位置
	if(ListDelete_L(L,i,e))  {
		printf("Deleted element: %d\n",e);
		printf("LinkList after Delete: ");
		TraverseList_L(L);
	}
	DestroyList_L(L);
	return 0;
}
//StudybarCommentEnd
