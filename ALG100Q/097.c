#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("097.db", "w");
    char c;
    while ((c = getchar()) && c != '#') {
        fprintf(fp, "%c", c);
    }
    fclose(fp);
    return 0;
}
