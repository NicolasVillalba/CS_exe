#lude <stdio.h>

int fun(int *s, int t, int *k) {
    int max = 1 << 31, i, index = 0;
    for(i = 0; i < t; ++i)
        if(s[i] > max)
        {
            max = s[i];
            index = i;
        }
    *k = index;
    return max;
}

int main(){
    int s[5] = {1, 2, 3, 4, 5}, t = 5, k;
    int res = fun(s, t, &k);
    printf("s[%d] = %d\n", k, res);
    return 0;
}
