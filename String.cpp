//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct {
	char* ch;
	int length;
} HString;
//StudybarCommentEnd
void StrAssign_HS(HString &S,char chars[])
{
	S.length = 0;
	int i = 0;
	int char_len = 0;
	while(chars[i] != '\0')
	{
		i++;
		char_len++;
	}
	if (!char_len)
	{
		S.ch = NULL;
		S.length = 0;
	}
	else
	{
	    if (S.ch) S.ch=NULL;
		i=0;
		S.ch = new char[char_len];
		int j = 0;
		int k = 0;
		while (k < char_len)
		{
			S.ch[k++] = chars[j++];
		}
		S.length = char_len;
	}
}

void StrPrint_HS(HString S)
{
	for (int i = 0; i < S.length; i++)
	{
		printf("%c", S.ch[i]);
	}
	printf("\nlength=%d\n",S.length);
}

void StrConcat_HS(HString &S1, HString S2)
{
	int S_len = S1.length + S2.length;
	int i = 0;
	HString e;
	e.ch=S1.ch;
	S1.ch=new char[S_len];
	for (; i < S1.length; i++)
	{
		S1.ch[i] = e.ch[i];
	}
	for (; i < S_len; i++)
	{
		S1.ch[i] = S2.ch[i-S1.length];
	}
	S1.length=S_len;
}

void StrReplace_HS(HString &S1, HString S2,int pos,int len)
{
	if((pos<1) || (pos>S1.length) || (len<0) || (len>S1.length-pos+1)) printf("Paramaters Error!");
    else
    {
    	int i=0,j=0,k=0;
    	char *a=new char[S1.length];
    	for(i=0;i<S1.length;i++)
    	    a[i]=S1.ch[i];
    	delete[] S1.ch;
    	S1.ch=new char[S1.length-len+S2.length];
    	for(i=0;i<pos-1;i++)
    	    S1.ch[i]=a[i];
    	for(j=0;j<S2.length;j++)
    	    S1.ch[i++]=S2.ch[j];
    	for(k=pos+len-1;k<S1.length;k++)
    	    S1.ch[i++]=a[k];
    	S1.length=S1.length-len+S2.length;
	}
}

void StrInsert_HS(HString &S1, HString S2,int pos)
{
    int i=0,j=0,k=0;
    char* a=new char[S1.length];
    for(i=0;i<S1.length;i++)
        a[i]=S1.ch[i];
    delete[] S1.ch;
    S1.ch=new char[S1.length+S2.length];
    for(i=0;i<pos-1;i++)
        S1.ch[i]=a[i];
    k=i;
    for(j=0;j<S2.length;j++)
        S1.ch[i++]=S2.ch[j];
    for(;i<S1.length+S2.length;k++)
        S1.ch[i++]=a[k];
    S1.length+=S2.length;
}

void DestroyString_HS(HString S)
{
    delete[] S.ch;
    S.length=0;
}

//StudybarCommentBegin
int main()  {
	HString a,b,c,d;
	char ch[MaxSize];
	int i,len;
	gets(ch);  StrAssign_HS(a,ch);	
	gets(ch);  StrAssign_HS(b,ch);	
	gets(ch);  StrAssign_HS(c,ch);
	gets(ch);  StrAssign_HS(d,ch);
	printf("\n");
	printf("a:\n");  StrPrint_HS(a);
	printf("b:\n");  StrPrint_HS(b);
	printf("c:\n");  StrPrint_HS(c);
	printf("d:\n");  StrPrint_HS(d);
	printf("\n");
	StrConcat_HS(a,b);
	printf("After merging, a:\n");
	StrPrint_HS(a);
	printf("\n");
	scanf("%d",&i);
	StrInsert_HS(a,c,i);
	printf("After inserting, a:\n");
	StrPrint_HS(a);
	printf("\n");
	scanf("%d%d",&i,&len);
	StrReplace_HS(a,d,i,len);
	printf("After replacing, a:\n");
	StrPrint_HS(a);
	DestroyString_HS(a);
	DestroyString_HS(b);
	DestroyString_HS(c);
	DestroyString_HS(d);
	return 0;
}
//StudybarCommentEnd
