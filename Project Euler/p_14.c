#include <stdio.h>

int count(long long int n)
{
    int cnt = 0;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = 3 * n + 1;
        }

        cnt++;
    }

    return cnt;
}

int main()
{
    int i, max_num = 0, max_cnt = 0, cnt;
    
    for (i = 1; i <= 1000000; i++) {
        cnt = count(i);

        if (cnt > max_cnt) {
            max_cnt = cnt;
            max_num = i;
        }
    }

    printf("%d %d\n", max_num, max_cnt);

    return 0;
}