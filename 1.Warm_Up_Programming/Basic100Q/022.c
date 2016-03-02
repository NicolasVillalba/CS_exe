//本题参考大神代码
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int score;
    struct Node *next;
}Node;

void add(Node *p, int sc) {
    Node *newNode = (Node*)malloc(sizeof(Node)), *tmp;
    newNode->score = sc;

    tmp = p->next;
    p->next = newNode;
    newNode->next = tmp;
}

Node* getListHeader() {
    Node *h = (Node*)malloc(sizeof(Node));
    h->next = NULL;
    h->score = -1;

    int i = 0, scores[] = {
        90, 91, 92, 93, 94, 95, 96, 97, 98, 99, -1
    };
    while(scores[i] != -1)
        add(h, scores[i++]);
    return h;
}

int fun(Node *p) {
    int max = 0;
    p = p->next;
    while(p) {
        if(p->score > max) max = p->score;
        p = p->next;
    }
    return max;
}

int main(){
    Node *h = getListHeader();
    printf("Max: %d\n", fun(h));
    return 0;
}
