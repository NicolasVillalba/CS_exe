#include <stdio.h>
#include <time.h>

int main(){
    clock_t start, end;
    int i;

    start = clock();

    for (i = 0; i < 10000; ++i) {
        end = clock();
        printf("%dth: %6.3f\n", i,(double)(end - start));
    }

    return 0;
}
