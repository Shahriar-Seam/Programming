#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, count = 0, i;
    char s[10], c;

    scanf("%d", &t);

    int arr[t];

    for (i = 0; i < t; i++) {
        scanf(" %s", s);

        c = s[0];

        if (c == 'A' || c == 'P' || c == 'O' || c == 'R') {
            arr[i] = 0;
        }
        else if (c == 'B' || c == 'M' || c == 'S') {
            arr[i] = 1;
        }
        else {
            arr[i] = 2;
        }
    }

    for (i = 0; i < t - 1; i++) {
        count += abs(arr[i] - arr[i + 1]);
    }

    printf("%d\n", count);

    return 0;
}