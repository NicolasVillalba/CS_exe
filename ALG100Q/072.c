#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

void reverse_construct(struct Node **head, int n) {
    if(n == 0) {
        *head = NULL;
        return;
    }

    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->next = NULL;
    scanf("%d", &(*head)->val);

    struct Node *p;

    while (--n) {
        p = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &p->val);
        p->next = *head;
        *head = p;
    }
}

void release(struct Node *p) {
    struct Node *t = p;
    while (p) {
        t = p;
        p = p->next;
        free(t);
    }
}

void print(struct Node *p) {
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
} // void print(struct Node *p)

int main(){
    struct Node *List;
    int n;
    printf("How many nodes do you want?\n");
    scanf("%d", &n);
    printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
    reverse_construct(&List, n);
    print(List);
    release(List);
    return 0;
}
