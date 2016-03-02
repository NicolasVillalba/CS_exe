#include<stdio.h>

int main()
{
	char i,j,k;/*i 是 a 的对手,j 是 b 的对手,k 是 c 的对手*/
	for(i='x';i<='z';i++)
		for(j='x';j<='z';j++)
		{
			if(i!=j)
				for(k='x';k<='z';k++)
				{
					if(i!=k&&j!=k)
					{
						if(i!='x'&&k!='x'&&k!='z')
						printf("order is a--%c\tb--%c\tc--%c\n",i,j,k);
					}		
				}
		}
	return 0;
}	
