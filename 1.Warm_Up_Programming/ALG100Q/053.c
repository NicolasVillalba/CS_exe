#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
} // void swap(int *a, int *b)


int main(){
    int a = 1, b = 2;
    printf("Before:\n");
    printf("a: %d\nb: %d\n", a, b);
    swap(&a, &b);
    printf("After:\n");
    printf("a: %d\nb: %d\n", a, b);
    return 0;
}
