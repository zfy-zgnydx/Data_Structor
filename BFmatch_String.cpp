//StudybarCommentBegin
#include<stdio.h>

#define STRING_SIZE 255
typedef unsigned char SString[STRING_SIZE+1];
//StudybarCommentEnd
void StrAssign_SS(unsigned char S[],char chars[])
{
	int i = 0;
	int char_len = 0;
	while(chars[i] != '\0')
	{
		i++;
		char_len++;
	}
	if (!char_len)
	{
		S[0] = 0;
	}
	else
	{
	    i=0;
		int j = 0;
		int k = 1;
		while (k <= char_len)
		{
			S[k++] = chars[j++];
		}
		S[0] = char_len;
	}
}
int StrIndex_BF(unsigned char S[],unsigned char T[],int pos)
{
	int t=1;
	int pos_t=1;
	int pos_s=pos;
	int match=0;
	while(pos<S[0]-T[0]+1 && pos_t<=T[0])
	{
		if(S[pos_s]!=T[pos_t])
		{
			pos_t=1;
			match=0;
			pos_s=++pos;
		}
		else
		{
			match++;
			pos_s++;
			pos_t++;
		}
	}
	if(match==T[0])return pos;
	else return 0;
}
//StudybarCommentBegin
int main()  {
	SString S,T;
	char char_s[STRING_SIZE],char_t[STRING_SIZE];
	int pos;
	printf("Input main string:\n");
	scanf("%s",char_s);
	StrAssign_SS(S,char_s);
	printf("Input pattern string:\n");
	scanf("%s",char_t);
	StrAssign_SS(T,char_t);
	printf("Input starting position:\n");
	scanf("%d",&pos);
	printf("Pattern matching results:\n%d\n",StrIndex_BF(S,T,pos));
	return 0;
}
//StudybarCommentEnd

