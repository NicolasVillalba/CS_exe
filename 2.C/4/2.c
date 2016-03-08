#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void Replace(char *s)
{
	int n = strlen(s);
	for(int i = 0; i < n; i++)
 	{
		if(s[i] != ' ') printf("%c", s[i]);
		else printf("%%020");
	}
}


int main()
{
	char s[] = "hello world how ";
	Replace(s);
	return 0;
}
