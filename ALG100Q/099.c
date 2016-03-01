#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 128

int cmp(const void *a, const void *b) {
    return *((char*)a) > *((char*)b);
}

int main(){
    FILE *fpA, *fpB, *fpC;
    fpA = fopen("099.A", "r");
    if(fpA == NULL) {
        fprintf(stderr, "cannot open file A.");
        exit(0);
    }

    fpB = fopen("099.B", "r");
    if(fpB == NULL) {
        fprintf(stderr, "cannot open file B.");
        exit(0);
    }

    fpC = fopen("099.C", "w");
    if(fpC == NULL) {
        fprintf(stderr, "cannot open file C.");
        exit(0);
    }

    char chs[MAXLEN], c;
    int i;
    while ((c = fgetc(fpA)) && c != EOF) {
        if(!isalpha(c)) continue;
        chs[i++] = c;
    }
    while ((c = fgetc(fpB)) && c != EOF) {
        if(!isalpha(c)) continue;
        chs[i++] = c;
    }

    qsort(chs, i, sizeof(char), cmp);
    chs[i] = '\0';
    i = 0;
    while (chs[i] != '\0') {
        fprintf(fpC, "%c", chs[i]);
        ++i;
    }
    return 0;
}
