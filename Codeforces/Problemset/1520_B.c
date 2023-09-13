#include <stdio.h>
#include <math.h>

long int makenum(int num, int count)
{
    long int result = num, i, p = 10;

    for (i = 1; i < count; i++) {
        result = result + num * p;
        p *= 10;
    }

    return result;
}

int determine(long int n)
{
    long int d = 10, r, mn;
    int t, i, count = 0, c = 0, j;

    while (1) {
        r = n / d;

        if (r > 0) {
            count += 9;
        }
        else {
            break;
        }

        d = d * 10;
        c++;
    }

    for (j = 1; j <= 9; j++) {
        mn = makenum(j, c + 1);

        if (mn <= n) {
            count++;
        }
        else {
            break;
        }
    }

    return count;
}

int main()
{
    int t, count;
    long int n;

    scanf("%d", &t);

    while (t--) {
        scanf("%ld", &n);
        
        count = determine(n);

        printf("%d\n", count);
    }

    return 0;
}