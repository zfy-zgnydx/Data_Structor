//StudybarCommentBegin
#include <stdio.h>

typedef int ElemType;

#define TriList_Size 1000 
typedef struct {
	int row, col;
	ElemType e;
}Triple;

typedef struct {
	Triple data[TriList_Size + 1];
	int mu, nu, tu;
}TSMatrix;
//StudybarCommentEnd
#include<iostream>
using namespace std;
void CreateSMatrix_TSM(TSMatrix &M)
{
	cout << "Input number of rows, columns and non-zero elements of Sparse Matrix:"<<endl;
	cin >> M.mu >> M.nu >> M.tu;
	cout << "Input non-zero values of Sparse Matrix in row-first order:" << endl;
	for (int i = 0; i < M.tu;i++)
	{
		cin >> M.data[i].row >> M.data[i].col >> M.data[i].e;
	}
}

void TransSMatrix_TSM(TSMatrix M, TSMatrix &T)
{
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu!=0)
	{
		int pt = 0;
		int i;
		for (i = 0; i < M.nu; ++i)
			for (int pm = 0; pm < M.tu; ++pm)
				if (M.data[pm].col == i)
				{
					T.data[pt].row = M.data[pm].col; T.data[pt].col = M.data[pm].row; T.data[pt].e = M.data[pm].e;
					++pt;
				}
	}
}
void TraverseSMatrix_TSM(TSMatrix M)
{
	for (int i = 0; i < M.tu; i++)
	{
		cout<< M.data[i].row <<" "<< M.data[i].col <<" "<< M.data[i].e<<endl;
	}
}

//StudybarCommentBegin
int main() {
	TSMatrix M, T1, T2;
	CreateSMatrix_TSM(M);
	printf("\nTriple Sequence Table:\n");
	TraverseSMatrix_TSM(M);
	TransSMatrix_TSM(M, T1);
	printf("\nDirect extraction and Sequential storage, Inverted Triple Sequence Table:\n");
	TraverseSMatrix_TSM(T1);
	return 0;
}
//StudybarCommentEnd
