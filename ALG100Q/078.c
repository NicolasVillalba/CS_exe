#include <stdio.h>
#define N 3
struct man {
    char name[20];
    int age;
};

struct man *fun(struct man P[], int n) {
    int old = P[0].age, id = 0, i;
    for (i = 0; i < n; ++i) {
        if(P[i].age > old) {
            old = P[i].age;
            id = i;
        }
    }
    return &P[id];
} // struct man * fun(int arg)


int main(){
    struct man Persion[N] = {
        "Xiao Ming", 12,
        "Lao Wang", 43,
        "Xiao Hong", 18
    };
    struct man *pOldest = fun(Persion, N);
    printf("%s\nAge: %d\n", pOldest->name, pOldest->age);
    return 0;
}
