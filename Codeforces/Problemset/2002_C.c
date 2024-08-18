#include <stdio.h>
#include <stdlib.h>

typedef struct point point;

struct point {
    int x;
    int y;
};

long long distance(int x1, int y1, int x2, int y2)
{
    return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
}

int solve()
{
    int n, i;
    long long dist;
    point start, end;

    scanf("%d", &n);

    point p[n];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    scanf("%d %d", &start.x, &start.y);
    scanf("%d %d", &end.x, &end.y);

    dist = distance(start.x, start.y, end.x, end.y);

    for (i = 0; i < n; i++) {
        if (dist >= distance(p[i].x, p[i].y, end.x, end.y)) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        puts(solve() ? "YES" : "NO");
    }

    return 0;
}