#include <stdio.h>

int main(){
    char *s[] = {
        "Hello",  " ", "World", "!", " ",
        "I'm", " ", "Coming", "!", "\n"
    };
    char **p;
    int i;

    for (i = 0; i < sizeof(s)/sizeof(*s); ++i) {
        p = &s[i];
        printf("%s", *p);
    }
    return 0;
}
