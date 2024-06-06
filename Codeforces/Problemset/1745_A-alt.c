#include <stdio.h>

unsigned long long int size = 100001;
unsigned long long int array[100002];  // Array[size + 1]

void fill_array()
{
    int i;

    for (i = 2; i <= size; i++) {
        array[i] = i;
    }
}

void find_primes()
{
    unsigned long long int i, j;

    for (i = 2; i * i <= size; i++) {
        if (array[i] != 0) {
            for (j = i * i; j <= size; j += i) {
                array[j] = 0;
            }
        }
    }
}

void primes()
{
    unsigned long long int i;

    for (i = 2; i <= size; i++) {
        if (array[i] != 0) {
            printf("%llu\n", array[i]);
        }
    }
}

int main()
{
    fill_array();
    find_primes();
    primes();

    return 0;
}