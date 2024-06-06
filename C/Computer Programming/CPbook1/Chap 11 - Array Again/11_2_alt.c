#include <stdio.h>

int multiplication_table(int arr[10][10])
{
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            arr[i][j] = (i + 1) * (j + 1);
        }
    }

    return arr;
}

int count_odd(int arr[10][10])
{
    int i, j, count = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (arr[i][j] % 2 != 0) {
                count++;
            }
        }
    }

    return count;
}

int count_even(int arr[10][10])
{
    int i, j, count = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (arr[i][j] % 2 == 0) {
                count++;
            }
        }
    }

    return count;
}

int sum(int arr[10][10])
{
    int i, j, sum = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}

int main()
{
    int table[10][10];
    int i, j;

    multiplication_table(table);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%4d\t", table[i][j]);
        }
        printf("\n");
    }

    printf("Odd Numbers: %d\n", count_odd(table));
    printf("Even Numbers: %d\n", count_even(table));
    printf("Sum of all the numbers: %d\n", sum(table));

    return 0;
}