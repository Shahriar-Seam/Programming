#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, m, mi = 0;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    m = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] < m) {
            m = arr[i];
            mi = i;
        }
    }

    cout << m << " " << mi + 1;

    return 0;
}