#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    clock_t start, end;
    int digit, n, flag = 1;
    char c;

    srand(time(NULL));

    while (1) {
        start = clock();
        digit = rand() % 10;

        printf("Guess!\n");
        while (flag) {
            scanf("%d", &n);
            if(n == digit) {
                flag = 0;
                end = clock();
            } else printf("Wrong! Try Again!\n");
        }

        printf("You Win!\nPlay Again? y or n\n");
        scanf(" %c", &c);
        if(c == 'n') break;
    }

    return 0;
}
