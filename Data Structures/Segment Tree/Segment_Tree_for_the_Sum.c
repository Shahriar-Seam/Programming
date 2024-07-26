#include <stdio.h>
#include <stdlib.h>

typedef struct segment_tree segment_tree;

struct segment_tree {
    long long *sums;
    int arr_size;
    int tree_size;
};

segment_tree *st;

// Initialize the tree structure
int *init(int n)
{
    st = (segment_tree *) malloc(sizeof(segment_tree));
    
    st->arr_size = 1;

    while (st->arr_size < n) {
        st->arr_size *= 2;
    }

    st->tree_size = 2 * st->arr_size;

    st->sums = (long long *) calloc(1LL * st->tree_size, sizeof(long long));

    return (int *) calloc(1LL * st->arr_size, sizeof(int));
}

// Build the tree using given array
void build_tree(int *arr, int x, int lx, int rx)
{
    if (rx - lx == 1) {
        if (lx < st->arr_size) {
            st->sums[x] = arr[lx];
        }

        return;
    }
    else {
        int mid = lx + (rx - lx) / 2;

        build_tree(arr, 2 * x + 1, lx, mid);
        build_tree(arr, 2 * x + 2, mid, rx);

        st->sums[x] = st->sums[2 * x + 1] + st->sums[2 * x + 2];
    }
}

void build(int *arr)
{
    build_tree(arr, 0, 0, st->arr_size);
}

// Update a value
void update_tree(int i, int v, int x, int lx, int rx)
{
    if (rx - lx == 1) {
        st->sums[x] = v;

        return;
    }
    else {
        int mid = lx + (rx - lx) / 2;

        if (i < mid) {
            update_tree(i, v, 2 * x + 1, lx, mid);
        }
        else {
            update_tree(i, v, 2 * x + 2, mid, rx);
        }

        st->sums[x] = st->sums[2 * x + 1] + st->sums[2 * x + 2];
    }
}

void update(int i, int v) {
    update_tree(i, v, 0, 0, st->arr_size);
}

// Calculate sum of given range
long long segment_sum(int l, int r, int x, int lx, int rx)
{
    if (lx >= r || rx <= l) {
        return 0;
    }
    else if (lx >= l && rx <= r) {
        return st->sums[x];
    }
    else {
        int mid = lx + (rx - lx) / 2;

        long long sum_left = segment_sum(l, r, 2 * x + 1, lx, mid);
        long long sum_right = segment_sum(l, r, 2 * x + 2, mid, rx);

        return sum_left + sum_right;
    }
}

long long sum(int l, int r)
{
    return segment_sum(l, r, 0, 0, st->arr_size);
}

// Helper/Debug Function
void print_tree()
{
    int i = 0, j = 0, k = 0;

    for (i = 0; j < st->tree_size; i++) {
        for (j, k = 0; k < (1 << i) && j < st->tree_size; k++, j++) {
            printf("%d ", st->sums[j]);
        }

        printf("\n");
    }

    printf("\n");
}

int main()
{
    int n, m, op, *arr;

    scanf("%d %d", &n, &m);

    arr = init(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    build(arr);

    while (m--) {
        scanf("%d", &op);

        if (op == 1) {
            int i, v;

            scanf("%d %d", &i, &v);

            update(i, v);
        }
        else {
            int l, r;

            scanf("%d %d", &l, &r);

            printf("%lld\n", sum(l, r));
        }
    }

    // print_tree();

    return 0;
}