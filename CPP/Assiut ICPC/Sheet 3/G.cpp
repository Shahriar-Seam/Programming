#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, j, p = 1;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0, j = n - 1; i < n / 2; i++, j--) {
        if (arr[i] != arr[j]) {
            p = 0;
            break;
        }
    }

    p ? cout << "YES" : cout << "NO";

    return 0;
}