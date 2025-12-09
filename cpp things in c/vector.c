#include <stdio.h>
#include <stdlib.h>

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
int store(vector *v, int index, type data);

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

int store(vector *v, int index, type data)
{
    if (index < 0 || index >= v->size) {
        return -1;
    }
    else {
        v->arr[index] = data;

        return 1;
    }
}

int main()
{
    int q, op, x, p;
    vector v;

    scanf("%d", &q);

    init(&v);

    while (q--) {
        scanf("%d", &op);

        if (op == 0) {
            scanf("%d", &x);

            push_back(&v, x);
        }
        else if (op == 1) {
            scanf("%d", &p);

            printf("%d\n", at(&v, p));
        }
        else {
            pop_back(&v);
        }
    }

    return 0;
}