#include <stdio.h>
#include <string.h>
void fun(char* s,const &char a){
	int i,j;
	for(i=0;s[i]!='\0';i++){
		if(s[i]==a){
			for(j=i;s[j+1]!='\0';j++){
				s[j]=s[j+1];
				}
			}
		else continue;
		}
	}
int main()
{
	char a[]="tfsadhfksahgsdkljwoih";
	char s='a';
	printf("%s\n",a);
	fun(a,s);
	printf("delete %c: %s\n",s,a);
}
