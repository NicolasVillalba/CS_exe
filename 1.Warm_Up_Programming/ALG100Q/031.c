#include <stdio.h>

/*
  Monday,Tuesday,Thursday,Wednesday,Friday,Saturday,Sunday

 */

int main(){
    char c, t;
    scanf("%c", &c);
    if(c == 'M') printf("Monday");
    else if(c == 'W') printf("Wednesday");
    else if(c == 'F') printf("Friday");
    else if(c == 'T') {
        printf("Input second character:");
        scanf(" %c", &c, &c);
        if(c == 'h') printf("Thursday");
        else if(c == 'u') printf("Tuesday");
    } else if(c == 'S') {
        printf("Input second character:");
        scanf(" %c", &c);
        if(c == 'a') printf("Saturday");
        else if(c == 'u') printf("Sunday");
    }
    printf("\n");
    return 0;
}
