#include <stdio.h>
#include <string.h>
#define MAXLEN 128

void swap(char **s1, char **s2) {
    char *t;
    if(strcmp(*s1, *s2) > 0) {
        t = *s1;
        *s1 = *s2;
        *s2 = t;
    }
} // void swap(char **s1, char **s2)


int main(){
    char s[3][MAXLEN];
    char *s1 = s[0], *s2 = s[1], *s3 = s[2];

    scanf("%s %s %s", s[0], s[1], s[2]);

    swap(&s1, &s2);
    swap(&s1, &s3);
    swap(&s2, &s3);

    printf("%s %s %s\n", s1, s2, s3);
    return 0;
}
