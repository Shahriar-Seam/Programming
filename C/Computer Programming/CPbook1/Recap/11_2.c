#include <stdio.h>

void ajaira_kam(int arr[10][10]);

int main()
{
    int mTable[10][10];
    int row, col;

    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            mTable[row][col] = (row + 1) * (col + 1);
        }
    }

    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            printf("%2d x %2d = %3d\n", row + 1, col + 1, mTable[row][col]);
        }

        printf("-------------\n");
    }

    ajaira_kam(mTable);

    return 0;
}

void ajaira_kam(int arr[10][10])
{
    int row, col;
    int odd = 0, even = 0, sum = 0;

    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            if (arr[row][col] % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }

            sum += arr[row][col];
        }
    }

    printf("Odd: %d\nEven: %d\nSum: %d\n", odd, even, sum);
}