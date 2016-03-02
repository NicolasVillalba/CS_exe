#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
} // void swap(int *a, int *b)


int encrypt(int n) {
    int nums[4], i, t;
    for (i = 0; i < 4; ++i) {
        nums[i] = (n % 10 + 5) % 10;
        n /= 10;
    }
    swap(&nums[0], &nums[3]);
    swap(&nums[1], &nums[2]);
    return nums[0] + nums[1] * 10 + nums[2] * 100 + nums[3] * 1000;
} // void encrypt(int n)


int main(){
    int data;
    scanf("%d", &data);
    printf("%d\n", encrypt(data));
    return 0;
}
