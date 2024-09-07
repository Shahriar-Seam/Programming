#include <stdio.h>

typedef struct pair pair;

struct pair {
    int two;
    int five;
};

pair make_pair(int two, int five)
{
    pair p;

    p.two = two;
    p.five = five;

    return p;
}

pair two_five(int n)
{
    int temp = n;
    pair p = make_pair(0, 0);

    while (n > 0 && n % 2 == 0) {
        n /= 2;
        p.two++;
    }
    
    n = temp;

    while (n > 0 && n % 5 == 0) {
        n /= 5;
        p.five++;
    }

    return p;
}

pair p_sum(pair p1, pair p2)
{
    pair p;

    p.two = p1.two + p2.two;
    p.five = p1.five + p2.five;

    return p;
}

int _min(int a, int b)
{
    return a < b ? a : b;
}

pair min(pair p1, pair p2)
{
    if (p1.two <= p2.two && p1.five <= p2.five) {
        return p1;
    }
    else if (p2.two <= p1.two && p2.five <= p1.five) {
        return p2;
    }
    else if (_min(p1.two, p1.five) <= _min(p2.two, p2.five)) {
        return p1;
    }
    else {
        return p2;
    }
}

int equal(pair p1, pair p2)
{
    return p1.two == p2.two && p1.five == p2.five;
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
    int n, i, j, k;
    int min_2, min_5, zero = 0, zero_i, zero_j;
    char c, s[10000];

    scanf("%d", &n);

    int arr[n][n];
    pair p[n][n], prev[n][n];
    int min_10[n][n];

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

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i][j].two = 0;
            p[i][j].five = 0;
        }
    }

    p[0][0] = two_five(arr[0][0]);
    prev[0][0] = make_pair(0, 0);

    for (i = 1; i < n; i++) {
        p[i][0] = p_sum(p[i - 1][0], two_five(arr[i][0]));

        prev[i][0] = make_pair(i - 1, 0);
    }

    for (j = 1; j < n; j++) {
        p[0][j] = p_sum(p[0][j - 1], two_five(arr[0][j]));

        prev[0][j] = make_pair(0, j - 1);
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            pair m = min(p[i - 1][j], p[i][j - 1]);
            
            if (equal(m, p[i - 1][j])) {
                prev[i][j] = make_pair(i - 1, j);
            }
            else {
                prev[i][j] = make_pair(i, j - 1);
            }

            p[i][j] = p_sum(m, two_five(arr[i][j]));
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            min_10[i][j] = _min(p[i][j].two, p[i][j].five);
        }
    }

    i = n - 1;
    j = n - 1;
    k = 0;

    while (i != 0 || j != 0) {
        int temp_i, temp_j;

        temp_i = prev[i][j].two;
        temp_j = prev[i][j].five;

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

    printf("%d\n%s\n", min_10[n - 1][n - 1], s);

    return 0;
}