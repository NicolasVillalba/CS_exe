#include <stdio.h>

void swap(int **a, int **b) {
    int *c;
    if(**a < **b) {
        c = *a;
        *a = *b;
        *b = c;
    }
} // void swap(int **a, int **b)


void fun(int a, int b, int c) {
    int *pa = &a, *pb = &b, *pc = &c;
    swap(&pa, &pb);
    swap(&pa, &pc);
    swap(&pb, &pc);
    printf("%d %d %d\n", *pa, *pb, *pc);
} // void fun(int a, int b, int c)


int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    fun(a, b, c);
    return 0;
}
