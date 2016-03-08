#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *convert(char *s)
{
	char t[10];
	int j, i;
	for(i = strlen(s) - 1; i > 0; i--)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
				for(int j = i; j > 0; j--)
				{
					if(s[j] < s[j - 1])
					{
						char temp = s[j];
						s[j] = s[j - 1];
						s[j - 1] = temp;
					}
				}
		}
	}
	return s;
}


int main()
{
	char s[] = "h1ell2o3";
	convert(s);
	printf("%s\n",s);
	return 0;
}
