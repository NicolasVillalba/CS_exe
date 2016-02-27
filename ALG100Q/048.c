#include <stdio.h>

#define EQ ==
#define LG >
#define LT <

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a EQ b) {
        printf("%d equals %d\n", a, b);
    } else if(a LT b) {
        printf("%d is less than %d\n", a, b);
    } else if(a LG b) {
        printf("%d is larger than %d\n", a, b);
    }
    return 0;
}
