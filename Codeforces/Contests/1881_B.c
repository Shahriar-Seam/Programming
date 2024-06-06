#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

void sort(int *a, int *b, int *c)
{
    int temp;

    if (*a < *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b < *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }

    if (*a < *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int t, a, b, c;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &c);

        sort(&a, &b, &c);

        if (a == b && b == c) {
            yes;
        }
        else if ((a % c == 0) && (b % c == 0) && ((a / c) + (b / c) <= 5)) {
            yes;
        }
        else {
            no;
        }
    }

    return 0;
}