#include <stdio.h>
#include <string.h>

void fun(char *sa[], int num, char **max) {
    int i, maxlen = 0;
    for(i = 0; i < num; ++i) {
        if(strlen(sa[i]) > maxlen) {
            maxlen = strlen(sa[i]);
            *max = sa[i];
        }
    }
}

int main(){
    char *s[] = {
        "Hello",
        "Hello world!",
        "Hello World!!!"
    };
    char *cp;
    fun(s, 3, &cp);
    printf("%s\n", cp);
    return 0;
}