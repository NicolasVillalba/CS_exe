#include <stdio.h>

#ifdef __linux__
#define MSG "Hello Linux!\n"
#elif __win32__
#define MSG "Hello Windows!\n"
#endif

int main(){
    printf(MSG);
    return 0;
}
