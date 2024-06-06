#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void solve()
{
    int n, first = 0, last = 0, i;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == arr[0]) {
            first++;
        }
        else {
            break;
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        if (arr[i] == arr[n - 1]) {
            last++;
        }
        else {
            break;
        }
    }

    if (arr[0] == arr[n - 1]) {
        printf("%d\n", max(n - (first + last), 0));
    }
    else {
        printf("%d\n", max(n - max(first, last), 0));
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}