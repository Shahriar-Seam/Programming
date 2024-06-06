#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, mi, ma, min_i, max_i, i;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ma = mi = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > ma) {
            ma = arr[i];
            max_i = i;
        }
        else if (arr[i] < mi) {
            mi = arr[i];
            min_i = i;
        }
    }

    arr[min_i] = ma;
    arr[max_i] = mi;

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    free(arr);

    return 0;
}