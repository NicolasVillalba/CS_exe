#include <stdio.h>

struct Student {
    int x;
    char c;
};

void fun(struct Student *s) {
    s->x = 10;
    s->c = 'P';
} // void fun(struct Student *s)

int main(){
    struct Student s = {1, 'p'};
    fun(&s);
    printf("%d %c\n", s.x, s.c);
    return 0;
}
