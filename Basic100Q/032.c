#include <stdio.h>
#include <string.h>

void fun(char *s, char *t) {
    int cnt = 0, i;
    for(i = 1; i < strlen(s); i += 2) {
        if(s[i] % 2 == 1) t[cnt++] = s[i];
    }
    s[cnt] = '0';
}

int main(){
    char s[] = "Hello, World!", t[100];
    fun(s, t);
    printf("%s\n", t);
    return 0;
}
