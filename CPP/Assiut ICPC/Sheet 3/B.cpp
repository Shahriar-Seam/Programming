#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, x, i, f = 0, ix = 0;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            f = 1;
            ix = i;
            break;
        }
    }

    f ? cout << ix : cout << -1;

    return 0;
}