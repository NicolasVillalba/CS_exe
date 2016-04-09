//大小端转换
#include <netinet/in.h>


int main()
{
    unsigned short  i = 0x1234;
    unsigned short j;
    j = htons(i);
    return 0;
}
