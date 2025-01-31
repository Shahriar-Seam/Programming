#include <stdio.h>
#include <stdlib.h>

#define type int
#define up 1
#define down -1
#define sz 500005
#define mod 100000007

typedef struct {
    type *arr;
    int size;
    int tail;
} vector;

int max(int a, int b);
void init(vector *v);
void init_with_size(vector *v, int s);
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

void init_with_size(vector *v, int s)
{
    v->size = 1;

    while (v->size < s) {
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
    if (index >= 0 && index < v->size) {
        return v->arr[index];
    }

    return 0; // garbage
}

void fibonacci(vector *fib)
{
    int i;

    init_with_size(fib, 3);

    fib->arr[0] = 0;
    fib->arr[1] = 1;
    fib->arr[2] = 1;

    fib->tail = 3;

    for (i = 3; i < sz; i++) {
        push_back(fib, (at(fib, i - 1) + at(fib, i - 2)) % mod);
    }
}

int main()
{
    vector fib;

    fibonacci(&fib);

    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        printf("%d\n", at(&fib, n));
    }

    return 0;
}