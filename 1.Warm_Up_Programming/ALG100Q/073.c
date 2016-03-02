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


int main(){
    struct Node *List;
    int n;
    printf("How many nodes do you want?\n");
    scanf("%d", &n);
    printf("Input %d numbers. \nList will be constructed in reverse order. \n", n);
    reverse_construct(&List, n);

    printf("\nNormal Order Print\n");
    print(List);

    printf("\nReverse Order Print\n");
    reverse_print(List);

    printf("\n");
    release(List);
    return 0;
}
