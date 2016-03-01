#include <stdio.h>
#include <time.h>

int main(){
    time_t start, end;
    int i;

    start = time(NULL);

    for (i = 0; i < 10000; ++i) {
        end = time(NULL);
        printf("%dth: %6.3f\n", i, difftime(end, start));
    }

    return 0;
}
