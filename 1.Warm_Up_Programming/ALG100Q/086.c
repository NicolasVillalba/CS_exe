#include <stdio.h>

void stringcat(char *ns, char *s1, char *s2) {
    int i = 0, j = 0;
    while (s1[i] != '\0') {
        ns[i] = s1[i];
        ++i;
    }
    while (s2[j] != '\0') {
        ns[i++] = s2[j++];
    }
    ns[i] = 0;
}

int main(){
    char s1[] = "Hello ", s2[] = "World!", s3[100];
    stringcat(s3, s1, s2);
    printf("%s\n", s3);
    return 0;
}
