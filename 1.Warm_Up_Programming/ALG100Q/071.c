#include <stdio.h>
#define N 5

typedef struct {
    char num[6];
    char name[8];
} Student;

void input(Student s[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", s[i].name);
        scanf("%s", s[i].num);
    }
} // void input(Student s[], int n)

void output(Student s[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%-6s %-6s\n", s[i].name, s[i].num);
    }
} // void output(Student s[], int n)

int main(){
    Student stus[N];
    input(stus, N);
    output(stus, N);
    return 0;
}
