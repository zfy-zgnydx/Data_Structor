//StudybarCommentBegin
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct CSNode {
	ElemType data;
	struct CSNode* firstchild, * rightsib;
}CSNode, * CSTree;
//StudybarCommentEnd

#include<queue>
using namespace std;
void InitTree_CST(CSTree &T)
{
	T = new CSNode;
	T->data = 0;
	T->firstchild = NULL;
	T->rightsib = NULL;
}

void CreateTree_CST(CSTree &T)
{
	int father, son;
	queue<CSTree> Q;
	for (scanf("%d%d", &father, &son); father != 0 && son != 0; scanf("%d%d", &father, &son))
	{
		
		CSTree p = new CSNode;
		CSTree Nfather;
		p->data = son;
		p->firstchild = NULL;
		p->rightsib = NULL;
		Q.push(p);
		if (father == -1)
		{
			T = p;
		}
		else
		{
			Nfather = Q.front();
			while (Nfather->data != father && Q.size()!=0)
			{
				Q.pop(); Nfather = Q.front();
			}
			if (Nfather->firstchild == NULL) Nfather->firstchild = p;
			else
			{
				Nfather = Nfather->firstchild;
				while (Nfather->rightsib != NULL)
				{
					Nfather = Nfather->rightsib;
				}
				Nfather->rightsib = p;
			}
		}
	}
}

void PreOrderTraverse_CST(CSTree T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		PreOrderTraverse_CST(T->firstchild);
		PreOrderTraverse_CST(T->rightsib);
	}
}

void PostOrderTraverse_CST(CSTree T)
{
	if (T != NULL)
	{
		PostOrderTraverse_CST(T->firstchild);printf("%d ", T->data);
		PostOrderTraverse_CST(T->rightsib);
		
	}
}

void FloorTraverse_CST(CSTree T)
{
	queue<CSTree> Q;
	Q.push(T);
	while (Q.size()!=0)
	{
		if (Q.front()->firstchild != NULL)
		{
			Q.push(Q.front()->firstchild);
			CSTree t = Q.front()->firstchild;
			while (t->rightsib != NULL)
			{
				Q.push(t->rightsib);
				t = t->rightsib;
			}
		}
		printf("%d ", Q.front()->data);
		Q.pop();
	}
}

void DestroyTree_CST(CSTree &T)
{
	
}

//StudybarCommentBegin
int main() {
	CSTree T;
	InitTree_CST(T);
	printf("Input tree:\n");
	CreateTree_CST(T);
	printf("\nPreordered sequence: ");
	PreOrderTraverse_CST(T);
	printf("\nPostordered sequence: ");
	PostOrderTraverse_CST(T);
	printf("\nFloorordered sequence: ");
	FloorTraverse_CST(T);
	printf("\n");
	DestroyTree_CST(T);
	return 0;
}
//StudybarCommentEnd
