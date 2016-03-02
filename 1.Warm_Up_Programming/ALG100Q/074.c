#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

void reverse_construct(struct Node **head, int n) {
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
}

void reverse_print(struct Node *p) {
    if(!p) return;
    reverse_print(p->next);
    printf("%d ", p->val);
}

void concatenate(struct Node **l1, struct Node **l2, struct Node **l3) {
    struct Node *p = (*l1)->next, *cur;
    cur = *l3 = *l1;

    while (p) {
        cur->next = p;
        cur = p;
        p = p->next;
    }

    p = (*l2);
    while (p) {
        cur->next = p;
        cur = p;
        p = p->next;
    }
    l1 = l2 = NULL;
}

int main(){
    struct Node *l1, *l2, *l3;
    int n;

    printf("How many nodes do you want for list 1?\n");
    scanf("%d", &n);
    printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
    reverse_construct(&l1, n);

    printf("How many nodes do you want for list 2?\n");
    scanf("%d", &n);
    printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
    reverse_construct(&l2, n);

    concatenate(&l1, &l2, &l3);

    print(l3);
    release(l3);
    return 0;
}
