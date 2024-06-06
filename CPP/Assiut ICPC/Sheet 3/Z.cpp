#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, *arr, x, i;
    bool f;

    cin >> n >> q;

    arr = new int[n];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    while (q--) {
        cin >> x;

        f = binary_search(arr, arr + n, x);

        f ? cout << "found\n" : cout << "not found\n";
    }

    return 0;
}