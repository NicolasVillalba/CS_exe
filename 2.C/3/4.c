#include<stdio.h>
//翻转，其实也是逆置，利用2个指针，分别从两端移动相遇前都交换相互指向的元素
void Reverse(char *pBegin, char *pEnd)
{
    if(pBegin == NULL || pEnd == NULL) return;

    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++, pEnd--;
    }
}

//翻转句子，也调用了上面的翻转函数
char *ReverseSentence(char *pData)
{
    if(pData == NULL) return NULL;

    //获得首指针
    char *pBegin = pData;

    //获得尾指针
    char *pEnd = pData;
    while(*pEnd != '\0') pEnd++;
    pEnd--;

    Reverse(pBegin, pEnd);//逆置句子

    pBegin = pEnd = pData;//逆置单词
    while(*pBegin != '\0')
    {
         if(*pBegin == ' ')
         {
             pBegin++;
             pEnd++;
         }else if(*pEnd == ' ' || *pEnd == '\0')
         {
              Reverse(pBegin, --pEnd);
              pBegin = ++pEnd;
         }else pEnd++;
    }
    return pData;
}

int main()
{
     char s[] = "I am a student.";
     ReverseSentence(s);
     printf("%s\n", s);
     return 0;
}

