//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//存储结构
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front;	//队头指针
	QueuePtr rear;	//队尾指针
}LinkQueue;
//StudybarCommentEnd
void InitQueue_L(LinkQueue& Q)
{
	Q.front = Q.rear=new QNode;
	Q.front->next = NULL;
}
void CreateQueue_L(LinkQueue& Q)
{
	int n;
	scanf("%d", &n);
	QueuePtr t = Q.front;
	for (int i = 0; i < n; i++)
	{
		QueuePtr temp = new QNode;
		scanf("%d", &temp->data);
		t->next = temp;
		t = t->next;
	}
	Q.rear = t;
	Q.rear->next = NULL;
}
void EnQueue_L(LinkQueue& Q, ElemType e)
{
	QueuePtr temp = new QNode;
	 temp->data=e;
	Q.rear->next = temp;
	Q.rear = Q.rear->next;
	Q.rear->next = NULL;
}
bool DeQueue_L(LinkQueue& Q, ElemType& e)
{
	if (Q.front->next != NULL)
	{
		QueuePtr temp = new QNode;
		temp = Q.front->next;
		e = temp->data;
		Q.front->next = Q.front->next->next;
		if (Q.front->next == NULL) Q.rear = Q.front;
		delete temp;
		return 1;
	}
	else
	{
		printf("Queue Empty!\n");
		return 0;
	}
}
void TraverseQueue_L(LinkQueue Q)
{
	QueuePtr temp = Q.front->next;
	while (temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void DestroyQueue_L(LinkQueue Q)
{
	QueuePtr temp = Q.front->next;
	while (temp)
	{
		QueuePtr q = temp;
		temp = temp->next;
		delete q;
	}
	Q.front->next = NULL;
	Q.rear = Q.front;
}

//StudybarCommentBegin
int main()
{
	LinkQueue Q;
	ElemType e;
	InitQueue_L(Q);
	CreateQueue_L(Q);
	printf("CreateQueue_L: ");
	TraverseQueue_L(Q);
	if (DeQueue_L(Q, e)) {
		printf("DeQueue element: %d\n", e);
		printf("LinkQueue after DeQueue: ");
		TraverseQueue_L(Q);
	}
	scanf("%d", &e);
	EnQueue_L(Q, e);
	printf("LinkQueue after EnQueue: ");
	TraverseQueue_L(Q);
	DestroyQueue_L(Q);
	return 0;
}
//StudybarCommentEnd
