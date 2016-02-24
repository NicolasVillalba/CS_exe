#include <stdio.h>

void fun(char s[], int n) {
    int i = 0, j = 0, cnt = 0;
    if(s[0] != '*') return;

    while(s[j] == '*') ++j;
    if(j == 2) return;

    if(j > 2) j -= 2;
    while(s[j] != '\0') {
        s[i++] = s[j++];
    }
    s[i] = '\0';
}

int main(){
    char s[] = "************H*e*l*l*o* *W*o*r*l*d****";
    fun(s, 2);
    printf("%s\n", s);
    return 0;
}
