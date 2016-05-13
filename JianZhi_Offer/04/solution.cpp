 #include <iostream>
#include <cstring>
using namespace std;


void print(char *s)
{
	int n = 0;
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == ' ') n++;
	}

	char str[n*2 + strlen(s) + 1];
	
	int j = 0;
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != ' ')
		{
			str[j++] = s[i];
		}else if(s[i] == ' ')
		{
			str[j++] = '%';
			str[j++] = '2';
			str[j++] = '0';
		}
	}
	str[j] = '\0';
	cout << str << endl;
}

int main()
{
	char s[] = "We are happy";
	print(s);
	return 0;
}
