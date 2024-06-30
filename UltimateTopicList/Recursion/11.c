#include <stdio.h>

int cnt = 0;

void count(int s, int e)
{
    if (s > e) {
        return;
    }

    if (s == e) {
        cnt++;

        return;
    }

    count(s + 1, e);
    count(s + 2, e);
    count(s + 3, e);
}

int main()
{
    int s, e;

    scanf("%d %d", &s, &e);

    count(s, e);

    printf("%d\n", cnt);

    return 0;
}