#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} item;

int compare(const void *a, const void *b)
{
    item *A = (item *) a;
    item *B = (item *) b;

    if (A->a + A->b < B->a + B->b) {
        return -1;
    }
    else if (A->a + A->b == B->a + B->b) {
        if (A->a < B->a) {
            return -1;
        }
        else if (A->a == B->a) {
            return A->b < B->b ? -1 : 1;
        }
        else {
            return 1;
        }
    }
    else {
        return 1;
    }
}

void solve()
{
    int n, i;

    scanf("%d", &n);

    item arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].a, &arr[i].b);
    }

    qsort(arr, n, sizeof(item), compare);

    for (i = 0; i < n; i++) {
        printf("%d %d ", arr[i].a, arr[i].b);
    }

    printf("\n");
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}