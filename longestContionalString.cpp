#include<stdio.h>

#define STRING_SIZE 255
typedef unsigned char SString[STRING_SIZE+1];
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
char* LLLPlatform(unsigned char S[])
{
	char Max_string;
	if(S[0]!=0)
	{
		//b=S[1];
	    Max_string=S[1];
    }
	int i=1;
	int Max_length=1;//Max_string的个数 
	int num1=1;//当前字符个数 
	while(i<S[0])
	{
		if(S[i]==S[i+1])
		{
			num1++;//printf("%c %d\n",S[i],num1); 
			i++;
		 } 
		else
		{
			if(Max_length<num1)
			{
				Max_string=S[i];
				Max_length=num1;
			  
			}	
			num1=1; 
			//printf("%c %d\n",S[i],num1);
			i++;
			//Max_string=S[++i];
		}
	}
	if(Max_length<num1)
	{
		Max_string=S[i];
		Max_length=num1;
		num1=1;   
	}
	char* c=new char[Max_length+1];
	for(int j=0;j<Max_length;j++)
	{
		c[j]=Max_string;
	}
	c[Max_length]='\0';
	return c;
}
void StrPrint_SS(unsigned char S[])
{
	for (int i = 1; i <= S[0]; i++)
	{
		printf("%c", S[i]);
	}
	printf("\n");
}
int main()  {
	SString S,t;
	char char_s[STRING_SIZE];
	scanf("%s",char_s);
	StrAssign_SS(S,char_s);
	printf("String:\n");
	StrPrint_SS(S);
	char* b=LLLPlatform(S);
	StrAssign_SS(t,b);
	printf("Longest platform:\n");
	StrPrint_SS(t);
	return 0;
}













