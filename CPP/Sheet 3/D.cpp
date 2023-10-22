#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        if (arr[i] <= 10) {
            printf("A[%d] = %d\n", i, arr[i]);
        }
    }

    return 0;
}