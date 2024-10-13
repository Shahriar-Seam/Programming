#include <stdio.h>
#include <stdlib.h>

#define size 100005

int *marked;

void sieve()
{
    int i, j;

    marked = (int *) calloc(size, sizeof(int));

    marked[0] = marked[1] = 1;

    for (i = 4; i < size; i += 2) {
        marked[i] = 1;
    }

    for (i = 3; i * i < size; i += 2) {
        if (marked[i] == 0) {
            for (j = i * i; j < size; j += i + i) {
                marked[j] = 1;
            }
        }
    }
}

int main()
{
    sieve();

    int n, i;

    scanf("%d", &n);

    printf("%d\n", (n > 2 ? 2 : 1));

    for (i = 2; i <= n + 1; i++) {
        printf("%d ", (marked[i] == 1 ? 2 : 1));
    }

    return 0;
}