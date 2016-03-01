#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 128

int main(){
    FILE *fp = fopen("098.db", "w");
    if(fp == NULL) {
        fprintf(stderr, "cannot open file.");
        exit(0);
    }

    char s[MAXLEN];
    int i = 0;
    fgets(s, MAXLEN, stdin);
    while (s[i] != '\0') {
        s[i] = toupper(s[i]);
        ++i;
    }
    fprintf(fp, "%s", s);
    fclose(fp);
    return 0;
}
