#include <stdio.h>
#include <string.h>

const int inf = 1e9;

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
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *s, int len)
{
    int i = 0;

    for (i = 0; i < len / 2; i++) {
        swap(s + i, s + len - i - 1);
    }
}

int recurse_2(int n, int twos[n][n], char *two_path, int i, int j, int visited[n][n])
{
    if (i == 0 && j == 0) {
        visited[0][0] = 1;
        two_path[0] = 'S';
        return twos[0][0];
    }

    if (i < 0 || j < 0) {
        return inf;
    }

    if (!visited[i][j]) {
        int up = recurse_2(n, twos, two_path, i - 1, j, visited);
        int left = recurse_2(n, twos, two_path, i, j - 1, visited);

        visited[i][j] = 1;

        if (up < left) {
            two_path[i + j] = 'D';
            twos[i][j] += up;
        }
        else {
            two_path[i + j] = 'R';
            twos[i][j] += left;
        }
    }

    return twos[i][j];
}

int recurse_5(int n, int fives[n][n], char *five_path, int i, int j, int visited[n][n])
{
    if (i == 0 && j == 0) {
        visited[0][0] = 1;
        five_path[0] = 'S';
        return fives[0][0];
    }

    if (i < 0 || j < 0) {
        return inf;
    }

    if (!visited[i][j]) {
        int up = recurse_5(n, fives, five_path, i - 1, j, visited);
        int left = recurse_5(n, fives, five_path, i, j - 1, visited);

        visited[i][j] = 1;

        if (up < left) {
            five_path[i + j] = 'D';
            fives[i][j] += up;
        }
        else {
            five_path[i + j] = 'R';
            fives[i][j] += left;
        }
    }

    return fives[i][j];
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int arr[n][n], twos[n][n], fives[n][n], visited[n][n];
    char two_path[100000], five_path[100000];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);

            twos[i][j] = two(arr[i][j]);
            fives[i][j] = five(arr[i][j]);
            visited[i][j] = 0;
        }
    }

    int two_cost = recurse_2(n, twos, two_path, n - 1, n - 1, visited);

    two_path[2 * n - 1] = '\0';

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    int five_cost = recurse_5(n, fives, five_path, n - 1, n - 1, visited);

    five_path[2 * n - 1] = '\0';

    if (two_cost < five_cost) {
        printf("%d\n", two_cost);

        for (i = strlen(two_path) - 2 * n + 2; two_path[i] != '\0'; i++) {
            printf("%c", two_path[i]);
        }
    }
    else {
        printf("%d\n", five_cost);

        for (i = strlen(five_path) - 2 * n + 2; five_path[i] != '\0'; i++) {
            printf("%c", five_path[i]);
        }
    }

    printf("\n");

    return 0;
}