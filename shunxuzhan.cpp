//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

#define STACK_INIT_SIZE 10
typedef struct {
	ElemType* elem;
	int top;
	int stacksize;
}SqStack;
//StudybarCommentEnd
void InitStack_Sq(SqStack& S)
{
	S.elem = new ElemType[STACK_INIT_SIZE];
	if (!S.elem)
	{
		printf("Overflow!");
		exit(0);
	}
	S.top = -1;
	S.stacksize = 0;
}
void CreateStack_Sq(SqStack& S)
{
	scanf("%d", &S.stacksize);
	if (S.stacksize > STACK_INIT_SIZE)
	{
		printf("Overflow!");
		exit(0);
	}
	for (int i = 0; i < S.stacksize; i++)
	{
		scanf("%d", &S.elem[i]);
		S.top++;
	}
}
void Push_Sq(SqStack& S, ElemType e)
{
	if (S.top < STACK_INIT_SIZE-1)
	{
		S.elem[++S.top] = e;
		S.stacksize++;
	}
	else
	{
		printf("Overflow!");
		exit(0);
	}
}
void Pop_Sq(SqStack& S, ElemType& e)
{
    if (S.top >= 0)
	    {
	    	e = S.elem[S.top--];
	    	S.stacksize--;
	    }
}
void TraverseStack_Sq(SqStack S)
{
	for (int i = 0; i <= S.top; i++)
	{
		printf("%d ", S.elem[i]);
	}
	printf("\n");
}
void DestroyStack_Sq(SqStack S)
{
	delete[] S.elem;
	S.top = -1;
	S.stacksize = 0;
}

//StudybarCommentBegin
int main() {
	SqStack S;
	ElemType e;
	InitStack_Sq(S);
	CreateStack_Sq(S);
	printf("CreateStack_Sq: ");
	TraverseStack_Sq(S);
	scanf("%d", &e);
	Push_Sq(S, e);
	printf("SqStack after Push: ");
	TraverseStack_Sq(S);
	Pop_Sq(S, e);
	printf_s("Top element is %d\n", e);
	printf_s("SqStack after Pop: ");
	TraverseStack_Sq(S);
	DestroyStack_Sq(S);
	return 0;
}
//StudybarCommentEnd
