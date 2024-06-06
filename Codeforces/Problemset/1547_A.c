#include <stdio.h>
#include <stdlib.h>

int _min(int a, int b)
{
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int _max(int a, int b)
{
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main()
{
    int x1, x2, y1, y2, f1, f2;
    int t, a, b;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &x1, &x2);
        scanf("%d %d", &y1, &y2);
        scanf("%d %d", &f1, &f2);

        a = abs(x2 - y2);
        b = abs(x1 - y1);

        if ((x1 == y1 && x1 == f1 && _min(x2, y2) < f2 && f2 < _max(x2, y2)) || (x2 == y2 && x2 == f2 && _min(x1, y1) < f1 && f1 < _max(x1, y1))) {
            printf("%d\n", a + b + 2);
        }
        else {
            printf("%d\n", a + b);
        }
    }

    return 0;
}