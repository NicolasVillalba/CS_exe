##题目

> 在字符串中找出第一个只出现一次的字符，如输入“abaccdeff”,则输出'b'


##思考

> 在思考过程中想到用哈希表进行定位，查找的时间复杂度为o(1)，实际上在初始化字符串的时候是要遍历一遍字符串的时间复杂度是o(n)。





###AC代码

```c++
#include<iostream>
#include<string>
using namespace std;




char FirstNotRepeatedChar(char *pString)
{
    if(pString == NULL) return '\0';//对于空字符串进行判断
    
    
    //1.初始化哈希表
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    
    for(int i = 0; i < tableSize; i++)
        hashTable[i] = 0;
    
    
    //2.将字符读入哈希表，即建立哈希表的过程
    char *pHashKey = pString;//创建一个指针指向字符串的的首地址相当于 char *pHashKey; pHashKey = pString;由于字符串的首地址就是字符串名字，不想要取地址符
    while(*(pHashKey) != '\0')
        hashTable[*(pHashKey++)]++;
        
    //3.重新开始遍历hash表
    pHashKey = pString;//表示地址
    while(*pHashKey != '\0')//解引用表示字符
    {
        if(hashTable[*pHashKey] == 1)
            return *pHashKey;
        
        pHashKey++;
    }
    return '\0';//这个是当所有的字符都不止出现一次的时候
}


int main()
{
    char s[100];
    cout << "Please input a string" << endl;
    cin >> s;
    cout << "The first no repeating char is "<< FirstNotRepeatedChar(s) << endl;
    return 0;
}
```
