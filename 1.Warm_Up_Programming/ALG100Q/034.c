#include <stdio.h>

void helloWorld() {
    printf("Hello World!\n");
} // void helloWorld()

void three_helloWorld() {
    int i;
    for (i = 0; i < 3; ++i) {
        helloWorld();
    }
} // void three_helloWorld()


int main(){
    three_helloWorld();
    return 0;
}
