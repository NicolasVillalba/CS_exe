#include <stdio.h>
#include <time.h>

int main(){
    time_t lt = time(NULL);
    printf("%s", ctime(&lt));
    printf("%s", asctime(localtime(&lt)));
    printf("%s", asctime(gmtime(&lt)));
    return 0;
}
