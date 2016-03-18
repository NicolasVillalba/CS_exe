//质因数分解，比如6的质因数为2和3，给定一个数，输出质因数



#include <stdio.h>

int main(){
	int n;  // 用户输入的整数
	int i;  // 循环标志

	printf("输入一个整数：");
	scanf("%d",&n);
	printf("%d=",n);


    //以下部分是重点，即求质因数的过程
	// n>=2才执行下面的循环
	for(i=2; i<=n; i++){//本循环是从2到n才结束
		while(n!=i){//
			if(n%i==0){
				printf("%d*",i);
				n=n/i;
			}else
				break;
		}
	}
	printf("%d\n",n);
	//

	return 0;
}
