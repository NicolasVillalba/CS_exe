#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OPTION_NUM 5
#define DB_FILE "money.db"

typedef struct Node {
    char date[20];
    char item[40];
    double price;
    int num;
    struct Node *next;
}Node;

int running = 1;
FILE *db_file = NULL;
Node head;
int num_records = 0;

void release() {
    Node *p = head.next, *to_del;
    while (p) {
        to_del = p;
        p = p->next;
        free(to_del);
    }
    head.next = NULL;
} // void release( )

void print_ui() {
    const char welcome[] = "Welcome to Money Management Helper v0.1";

    const char prompt[] = "Options:";
    const char options[OPTION_NUM][20] = {
        "1.Init Database",
        "2.New record",
        "3.Delete record",
        "4.List all records",
        "5.Exit",
    };
    printf("%s\n\n", welcome);
    printf("%s\n", prompt);
    int i;
    for (i = 0; i < OPTION_NUM; ++i) {
        printf("%s", options[i]);
        if(i % 2) printf("\n");
        else printf("\t\t");
    }
    printf("\n\n");
} // void print_ui()

int getOption() {
    int op;
    printf("Please Select One Option: ");
    scanf("%d", &op);
    return op;
}

void init() {
    if(db_file) {
        db_file = freopen(NULL, "w+", db_file);
        printf("Reset data file \"money.db\"\n\n");
        release();
    } else {
        db_file = fopen(DB_FILE, "w+");
        printf("Created data file \"money.db\"\n\n");
    }
    num_records = 0;
} // void init()

Node *new_record() {
    Node *new = (Node*)malloc(sizeof(Node));
    new->next = NULL;

    printf("Please input item name: ");
    scanf("%s", new->item);
    printf("Please input price: ");
    scanf("%lf", &new->price);
    printf("Please input number: ");
    scanf("%d", &new->num);
    printf("Please input date(eg: 2015-05-01): ");
    scanf("%s", new->date);
    printf("\n");
    return new;
} // void new_record()

void insert(Node *n) {
    n->next = head.next;
    head.next = n;
    ++num_records;
    //printf("New record inserted.\n\n");
}

void list_record(Node *node, int id) {
    if(!node) return;
    list_record(node->next, id - 1);
    printf("%d\t%12s\t%12s\t%8.2lf\t%4d\n", id, node->date, node->item,
           node->price, node->num);
}

void print_all() {
    printf("%s\t%12s\t%12s\t%8s\t%6s\n", "Id", "Date", "Item",
           "Price", "Num");
    list_record(head.next, num_records);
    printf("\n");
} // void print_all()

Node *do_delete(Node *node, int id) {
    if(id == 1) {
        --num_records;
        Node *tmp = node->next->next, *ret = node->next;
        node->next = tmp;
        return ret;
    } else return do_delete(node->next, --id);
}

void delete_record() {
    int id;
    printf("Please insert the id to delete: ");
    scanf("%d", &id);

    if(id <= 0 || id > num_records) {
        fprintf(stderr, "Index Out Of Range!\n");
        return;
    }
    Node *deleted = do_delete(head.next, id);
    printf("Deleted %s\n", deleted->item);
    free(deleted);
}

void read_db() {
    db_file = fopen(DB_FILE, "r");
    if(db_file == NULL) {
        init();
        return;
    }

    Node *tmp = (Node*)malloc(sizeof(Node));

    num_records = 0;
    while (1 == fread(tmp, sizeof(*tmp), 1, db_file)) {
        tmp->next = head.next;
        head.next = tmp;
        ++num_records;
        tmp = (Node*)malloc(sizeof(Node));
    }
    free(tmp);
} // void read_db()

void write_record(Node *node) {
    if(!node) return;
    write_record(node->next);
    if(1 != fwrite(node, sizeof(Node), 1, db_file)) {
        fprintf(stderr, "Cannot write to data file.\n");
        return;
    }
}

void write_db() {
    db_file = freopen(NULL, "r+", db_file);
    write_record(head.next);
    release();
    fclose(db_file);
} // void write_db()

int main(){
    print_ui();
    //time_t lt = time(NULL);
    //printf("%s\n", asctime(localtime(&lt)));
    read_db();
    while (running) {
        switch(getOption()) {
        case 1:
            init();
            break;
        case 2:
            insert(new_record());
            break;
        case 3:
            delete_record();
            break;
        case 4:
            print_all();
            break;
        case 5:
            running = 0;
            break;
        default:
            printf("ERROR INPUT!\n\n");
        }
    }
    write_db();
    return 0;
}
