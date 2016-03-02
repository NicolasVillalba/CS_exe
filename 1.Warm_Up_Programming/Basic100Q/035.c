//本体参考大神代码
#include <stdio.h>
#include <string.h>

void fun(char *s) {
    int i, j;
    for(i = 0; i < strlen(s); ++i) {
        if(s[i] != ' ') continue;
        j = i + 1;
        while(s[j] == ' ') ++j;
        printf("%d %d\n", i, j);
        s[i] = s[j];
        s[j] = ' ';
    }
}

int main(){
    char s[] = "Hello ll ss s sw eal ";
    fun(s);
    printf("\"%s\"\n", s);
    return 0;
}
