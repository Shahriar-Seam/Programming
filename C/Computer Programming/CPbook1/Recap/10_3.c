#include <stdio.h>

int size = 101;
int array[102];  // Array[size + 1]

void fill_array()
{
    int i;

    for (i = 2; i <= size; i++) {
        array[i] = i;
    }
}

void find_primes()
{
    int i, j;

    for (i = 2; i * i <= size; i++) {
        if (array[i] != 0) {
            for (j = i * i; j <= size; j += i) {
                array[j] = 0;
            }
        }
    }
}

void print_primes()
{
    int i;

    for (i = 2; i <= size; i++) {
        if (array[i] != 0) {
            printf("%d\n", array[i]);
        }
    }
}

int main()
{
    fill_array();
    find_primes();
    print_primes();

    return 0;
}

// https://chat.openai.com/share/47944300-e2f3-4e39-9dee-08f73606b47b