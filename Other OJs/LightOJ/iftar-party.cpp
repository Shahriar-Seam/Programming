#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define int long long
#define type int
#define up 1
#define down -1

typedef struct {
    type *arr;
    int size;
    int tail;
} vector;

int max(int a, int b);
void init(vector *v);
void init_with_size(vector *v, int sz);
void push_back(vector *v, type data);
void pop_back(vector *v);
void resize(vector *v, int t);
type at(vector *v, int index);

int max(int a, int b)
{
    return a > b ? a : b;
}

void init(vector *v)
{
    v->arr = (type *) calloc(1, sizeof(type));

    v->size = 1;

    v->tail = 0;
}

void init_with_size(vector *v, int sz)
{
    v->size = 1;

    while (v->size < sz) {
        v->size *= 2;
    }

    v->arr = (type *) calloc(v->size, sizeof(type));

    v->tail = 0;
}

void push_back(vector *v, type data)
{
    if (v->tail == v->size) {
        resize(v, up);
    }

    v->arr[v->tail] = data;

    v->tail++;
}

void pop_back(vector *v)
{
    if (v->tail > 0) {
        v->tail--;

        v->arr[v->tail] = 0;

        if (v->tail == v->size / 4) {
            resize(v, down);
        }
    }
}

void resize(vector *v, int t)
{
    type *temp = (type *) calloc(v->size, sizeof(type));
    int i;

    for (i = 0; i < v->tail; i++) {
        temp[i] = v->arr[i];
    }

    free(v->arr);

    if (t == up) {
        v->size = v->size * 2;

        v->arr = (type *) calloc(v->size, sizeof(type));
    }
    else {
        v->size = max(1, v->size / 2);

        v->arr = (type *) calloc(v->size, sizeof(type));
    }

    for (i = 0; i < v->tail; i++) {
        v->arr[i] = temp[i];
    }
}

type at(vector *v, int index)
{
    if (index >= 0 && index < v->tail) {
        return v->arr[index];
    }

    return 0; // garbage
}

void merge_sort(int *arr, int *temp, int l, int r)
{
    int mid = (l + r) / 2;

    if (r - l == 1) {
        return;
    }

    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid, r);

    int i, j, k;

    for (i = l, j = mid, k = l; k < r; k++) {
        temp[k] = (i < mid && j < r) ? (arr[i] < arr[j] ? arr[i++] : arr[j++]) : (i < mid ? arr[i++] : arr[j++]);
    }

    for (k = l; k < r; k++) {
        arr[k] = temp[k];
    }
}

int32_t main()
{
    int t, j(1);

    for (scanf("%d", &t); t; ++j, --t) {
        printf("Case %d:", j);

        long long p, l, i;

        scanf("%lld %lld", &p, &l);

        if (2 * l >= p) {
            printf(" impossible\n");

            continue;
        }

        vector divisors;
        long long n = p - l;
        
        init(&divisors);

        for (i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                push_back(&divisors, i);

                if (n / i != i) {
                    push_back(&divisors, n / i);
                }
            }
        }

        vector temp;

        init_with_size(&temp, divisors.size);

        merge_sort(divisors.arr, temp.arr, 0, divisors.tail);

        for (i = 0; i < divisors.tail; ++i) {
            if (at(&divisors, i) > l) {
                printf(" %lld", at(&divisors, i));
            }
        }

        printf("\n");
    }

    return 0;
}