#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *DeleteA(char *s)
{
	int lenth = strlen(s);
	int i, j = 0;
	for(i = 0; i < lenth; i++)
		if(s[i] != 'a') s[j++] = s[i];
	s[j] = '\0';
	return s;
}


int main()
{
	char s[] = " abcdaefaghiagkl";
	DeleteA(s);
	printf("%s\n", s);
	return 0;
}


