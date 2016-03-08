#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *DeleteSpace(char *s)
{
	int lenth = strlen(s);
	int j = 0;
	int i = 1;
	while(i != lenth-1)
	{
		if(s[0] == ' ')  s[j++] = s[i++];
		
		if(s[i] != ' ') s[j++] = s[i];
		if(s[i] == ' ')
		{
			s[j++] = ' ';
			while( s[i] == ' ') i++;
		}else i++;
	}
	if(s[lenth - 1] == ' ') s[j] = '\0';
	else {
		s[j++] = s[lenth - 1]; s[j] = '\0';
	}
	return s;
}

int main()
{
	char s[] = " hello  world   how are you ";
	DeleteSpace(s);
	printf("%s", s);
	printf("*\n");
	return 0;
}
