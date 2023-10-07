#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, t, i;
    int r = 0, sum = 0, books = 0;
    int *arr;

    scanf("%d %d", &n, &t);

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        while (r < n && sum + arr[r] <= t) {
            sum += arr[r];
            r++;
        }

        books = (books > (r - i)) ? books : r - i;
        sum -= arr[i];
    }

    printf("%d\n", books);

    return 0;
}