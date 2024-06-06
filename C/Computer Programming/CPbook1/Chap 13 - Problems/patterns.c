#include <stdio.h>

void one(int n);
void two(int n);
void three(int n);
void four(int n);

int main()
{
    int n, t;

    while (1) {
        printf("Enter pattern number (1/2/3/4)\nEnter 0 to exit: ");
        scanf("%d", &t);

        if (t == 0) {
            break;
        }

        if (t == 1) {
            printf("Enter a number: ");
            scanf("%d", &n);

            one(n);
        }

        else if (t == 2) {
            printf("Enter a number: ");
            scanf("%d", &n);

            two(n);
        }

        else if (t == 3) {
            printf("Enter a number: ");
            scanf("%d", &n);

            three(n);
        }

        else if (t == 4) {
            printf("Enter a number: ");
            scanf("%d", &n);

            four(n);
        }
    }

    return 0;
    
}

void one(int n)
{
        int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i; j++) {
            printf("C");
        }

        if (i == n - 2) {
            break;
        }

        printf("\n");
    }

    for (i = 0; i <= n; i++) {
        for (j = i; j > 0; j--) {
            printf("C");
        }

        printf("\n");
    }

    return;
}

void two(int n)
{
        int i, j, k;

    for (i = 0; i < n - 1; i++) {
        for (j = i; j > 0; j--) {
            printf(" ");
        }

        for (k = 2 * (n - i) - 1; k > 0; k--) {
            printf("C");
        }

        if (i == n - 2) {
            break;
        }

        printf("\n");
    }

    for (i = 0; i <= n; i++) {
        for (j = i - 1; j < n - 1; j++) {
            printf(" ");
        }

        for (k = 0; k < 2 * i - 1; k++) {
            printf("C");
        }

        printf("\n");
    }

    return;
}

void three(int n)
{
        int i, j, k;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        for (k = 0; k < n - i; k++) {
            printf("C");
        }

        if (i == n - 1) {
            break;
        }

        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        for (k = 0; k <= i; k++) {
            printf("C");
        }

        printf("\n");
    }

    return;
}

void four(int n)
{
        int i, j, k, m;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("C");
        }

        for (k = 0; k < 2 * (n - i) - 2; k++) {
            printf(" ");
        }

        for (m = 0; m <= i; m++) {
            printf("C");
        }

        printf("\n");
    }

    return;
}