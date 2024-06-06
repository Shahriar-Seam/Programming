#include <stdio.h>

void sieve(int array[], int size)
{
    int i, j;

    for (i = 2; i <= size; i++) {
        array[i] = i;
    }

    for (i = 2; i * i <= size; i++) {
        if (array[i] != 0) {
            for (j = i * i; j <= size; j += i) {
                array[j] = 0;
            }
        }
    }
}

int main()
{
    int size = 150000;
    int array[size + 2];

    sieve(array, size);

    int count = 0;
    for (int i = 2; i <= size; i++) {
        if (array[i] != 0) {
            count++;
            if (count == 10001) {
                printf("%d\n", array[i]);
                break;
            }
        }
    }

    return 0;
}
