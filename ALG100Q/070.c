#include <stdio.h>
#define N 100

int len(char s[]) {
    int ret = 0;
    while (s[ret] != '\0') {
        ++ret;
    }
    return ret;
} // int len(char s[])

int main(){
    char s[N];
    scanf("%s", s);
    printf("length: %d\n", len(s));
    return 0;
}
