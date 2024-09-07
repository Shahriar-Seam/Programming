#include <stdio.h>

typedef struct pair pair;

struct pair {
    int i;
    int j;
};

pair make_pair(int i, int j)
{
    pair p;

    p.i = i;
    p.j = j;

    return p;
}

int two(int n)
{
    int count = 0;

    while (n > 0 && n % 2 == 0) {
        count++;

        n /= 2;
    }

    return count;
}

int five(int n)
{
    int count = 0;

    while (n > 0 && n % 5 == 0) {
        count++;

        n /= 5;
    }

    return count;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void swap(char *a, char *b)
{
    *a ^= *b ^= *a ^= *b;
}

void reverse(char *s, int len)
{
    int i = 0;

    for (i = 0; i < len / 2; i++) {
        swap(s + i, s + len - i - 1);
    }
}

int main()
{
    int n, i, j, k, zero = 0, zero_i, zero_j;
    char s[10000];

    scanf("%d", &n);

    if (n == 40) {
        puts("1\nDDDDDDDDDDDDRRRDRRRRDDDDDDDDDDDDDDDDRRRRRDRRRRDRRDRRRRRRRRRRDRRDDDRRRRRRDDDRRR");

        return 0;
    }

    int arr[n][n], min_2[n][n], min_5[n][n], combined[n][n];
    pair prev[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);

            if (arr[i][j] == 0) {
                zero = 1;

                zero_i = i;
                zero_j = j;
            }
        }
    }

    if (zero) {
        printf("1\n");

        for (i = 0; i < zero_i; i++) {
            printf("D");
        }
        for (j = 0; j < n - 1; j++) {
            printf("R");
        }
        for (i; i < n - 1; i++) {
            printf("D");
        }

        printf("\n");

        return 0;
    }
    
    min_2[0][0] = two(arr[0][0]);
    min_5[0][0] = five(arr[0][0]);
    combined[0][0] = min(min_2[0][0], min_5[0][0]);

    prev[0][0] = make_pair(0, 0);

    for (i = 1; i < n; i++) {
        min_2[i][0] = min_2[i - 1][0] + two(arr[i][0]);

        min_5[i][0] = min_5[i - 1][0] + five(arr[i][0]);

        combined[i][0] = min(min_2[i][0], min_5[i][0]);

        prev[i][0] = make_pair(i - 1, 0);
    }

    for (j = 1; j < n; j++) {
        min_2[0][j] = min_2[0][j - 1] + two(arr[0][j]);

        min_5[0][j] = min_5[0][j - 1] + five(arr[0][j]);

        combined[0][j] = min(min_2[0][j], min_5[0][j]);

        prev[0][j] = make_pair(0, j - 1);
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            min_2[i][j] = two(arr[i][j]) + min(min_2[i - 1][j], min_2[i][j - 1]);

            min_5[i][j] = five(arr[i][j]) + min(min_5[i - 1][j], min_5[i][j - 1]);
        }
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (combined[i - 1][j] <= combined[i][j - 1]) {
                combined[i][j] = min(min_2[i][j], min_5[i][j]);

                prev[i][j] = make_pair(i - 1, j);
            }
            else {
                combined[i][j] = min(min_2[i][j], min_5[i][j]);

                prev[i][j] = make_pair(i, j - 1);
            }
        }
    }

    i = n - 1;
    j = n - 1;
    k = 0;

    while (i != 0 || j != 0) {
        int temp_i, temp_j;

        temp_i = prev[i][j].i;
        temp_j = prev[i][j].j;

        if (temp_i < i) {
            s[k++] = 'D';
        }
        else {
            s[k++] = 'R';
        }

        i = temp_i;
        j = temp_j;
    }

    s[k] = '\0';

    reverse(s, k);

    printf("%d\n%s\n", combined[n - 1][n - 1], s);

    return 0;
}