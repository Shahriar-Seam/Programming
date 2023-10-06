#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int max_dist(int *a, int n)
{
    int i, d, max = -1;

    for (i = 1; i < n; i++) {
        d = a[i] - a[i - 1];

        if (d > max) {
            max = d;
        }
    }

    return max;
}

double _max(double a, double b, double c) {
    if (a > b && a > c) {
        return a;
    }
    else if (b > a && b > c) {
        return b;
    }
    else {
        return c;
    }
}

int main()
{
    int n, l, i;
    int *a;

    scanf("%d %d", &n, &l);

    a = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    int md = max_dist(a, n);

    double d = _max((double) md / 2, (double) a[0], (double) l - a[n - 1]);

    printf("%0.9lf", d);

    return 0;
}

/*
This code works fine on my computer.
I submitted it to codeforces selecting language "GNU GCC C11 5.1.0".
But the judge shows wrong answer.
Then after selecting language "GNU G++20 11.2.0 (64 bit, winlibs)" the judge accepted the same code.
*/