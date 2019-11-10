//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//存储结构
#define LIST_INIT_SIZE 10
typedef struct  {
	ElemType *elem;
	int length;
	int listsize;
}SqList;
//StudybarCommentEnd
void InitList_Sq(SqList &L)
{
	L.elem=new ElemType[LIST_INIT_SIZE];
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
}

void CreateList_Sq(SqList &L)
{
	int n;
	scanf("%d",&n);
	L.length=n;
	if(n>10||n<1)
	{
		printf("Overflow!");
		exit(0);
	}
	for(int i=0;i<L.length;i++)
	{
		scanf("%d",&L.elem[i]);
	}
}

void InsertElem_Sq(SqList &L,int i,ElemType e)
{
	if(i<1 || i>L.length+1)
	{
		printf("Position Error!");
		exit(0);
	}
	L.length++;
	if(L.length>L.listsize)
	{
		printf("Overflow!");
		exit(0);
	}
	for(int j=L.length;j>=i;j--)
	{
		L.elem[j]=L.elem[j-1];
	}
	L.elem[i-1]=e;
	
}

void DeleteElem_Sq(SqList &L,int i,ElemType &e)
{
	if(i<1 || i>L.length)
	{
		printf("Position Error!");
		exit(0);
	}
	e=L.elem[i-1];
	for(int j=i-1;j<L.length;j++)
	{
		L.elem[j]=L.elem[j+1];
	}
	L.elem[L.length-1]=NULL;
	L.length--;
}

void TraverseList_Sq(SqList L)
{
	for(int i=0;i<L.length;i++)
	{
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

void DestroyList_Sq(SqList L)
{
	delete[] L.elem;
	L.length=0;
	L.listsize=0;
}
//StudybarCommentBegin
int main()  {
	SqList L;
	ElemType e;
	int i;
	InitList_Sq(L);
	CreateList_Sq(L);
	printf("CreateList_Sq: ");
	TraverseList_Sq(L);
	scanf("%d%d",&i,&e);			//插入位置和元素
	InsertElem_Sq(L,i,e);
	printf("SqList after Insert: ");
	TraverseList_Sq(L);
	scanf("%d",&i);				//删除位置
	DeleteElem_Sq(L,i,e);
	printf("Deleted element: %d\n",e);
	printf("SqList after Delete: ");
	TraverseList_Sq(L);
	DestroyList_Sq(L);
	return 0;
}
//StudybarCommentEnd
