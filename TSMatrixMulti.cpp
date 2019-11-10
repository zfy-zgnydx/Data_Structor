//StudybarCommentBegin
#include <stdio.h>
//StudybarCommentEnd

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
int min(int x, int y)
{
	if (x < y) return x;
	else return y;
}
void Mult(int A[100], int B[100], int C[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = 0;
			int ia=i, ja=0, ib=0, jb=j;
			while (ja < n)
			{
				int loca, locb;
				int imaxa=max(ia,ja), jmaxa=min(ia,ja),imaxb=max(ib,jb),jmaxb=min(ib,jb);
				loca = imaxa * (imaxa + 1) / 2 + jmaxa;
				locb = imaxb * (imaxb + 1) / 2 + jmaxb;
				C[i][j] += A[loca] * B[locb];
				ja++;
				ib++;
			}
		}
	}
}

void Print(int C[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%8d ", C[i][j]);
		}
		printf("\n");
	}
}

//StudybarCommentBegin
int main() {
	int n, i, j;
	int A[100], B[100], C[100][100];
	scanf_s("%d", &n);
	for (i = 0; i < n * (n + 1) / 2; i++)  scanf_s("%d", &A[i]);
	for (i = 0; i < n * (n + 1) / 2; i++)  scanf_s("%d", &B[i]);
	Mult(A, B, C, n);
	printf("\nA*B:\n");
	Print(C, n);
	return 0;
}
//StudybarCommentEnd
