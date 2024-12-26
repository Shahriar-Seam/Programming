#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#define int long long
#define read(p) scanf("%lld %lld %lld %lld", &p.x, &p.y, &p.a, &p.b)
#define print(p) printf("%lld %lld\n", p.x, p.y)

typedef struct {
    int x, y;
    int a, b;
} point;

point rotate(point p, int count)
{
    point q = p;

    if (count != 0) {
        q.x = p.a - (p.y - p.b);
        q.y = p.b + (p.x - p.a);


        q.a = p.a;
        q.b = p.b;
    }

    return q;
}

int distance(point p1, point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void sort(int *l1, int *l2, int *l3, int *l4, int *l5, int *l6)
{
    int arr[6] = {*l1, *l2, *l3, *l4, *l5, *l6};
    int temp;
    int i, j;

    for (i = 0; i < 6; i++) {
        for (j = i + 1; j < 6; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];

                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    *l1 = arr[0];
    *l2 = arr[1];
    *l3 = arr[2];
    *l4 = arr[3];
    *l5 = arr[4];
    *l6 = arr[5];
}

void solve()
{
    point p1, p2, p3, p4;
    int i, j, k, l, n = 4;
    int l1, l2, l3, l4, l5, l6;
    int min_moves = INT_MAX;

    read(p1);
    read(p2);
    read(p3);
    read(p4);

    for (i = 0; i <= n; i++) {
        p1 = rotate(p1, i);

        for (j = 0; j <= n; j++) {
            p2 = rotate(p2, j);

            for (k = 0; k <= n; k++) {
                p3 = rotate(p3, k);

                for (l = 0; l <= n; l++) {
                    p4 = rotate(p4, l);

                    l1 = distance(p1, p2);
                    l2 = distance(p1, p3);
                    l3 = distance(p1, p4);
                    l4 = distance(p2, p3);
                    l5 = distance(p2, p4);
                    l6 = distance(p3, p4);

                    sort(&l1, &l2, &l3, &l4, &l5, &l6);

                    if (l1 == l2 && l2 == l3 && l3 == l4 && l5 == l6 && l1 > 0) {
                        min_moves = min(min_moves, i + j + k + l);
                    }
                }
            }
        }
    }

    printf("%lld\n", min_moves == INT_MAX ? -1 : min_moves);
}

int32_t main()
{
    int t;

    scanf("%lld", &t);

    while (t--) {
        solve();
    }

    return 0;
}