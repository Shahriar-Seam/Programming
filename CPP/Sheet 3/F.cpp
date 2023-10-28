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

    for (i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}