#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, j, k = 0, f = 1;
    int *arr1, *arr2, *arr;

    cin >> n >> m;

    arr1 = (int *) malloc(sizeof(int) * n);
    arr2 = (int *) malloc(sizeof(int) * m);
    arr = (int *) malloc(sizeof(int) * m);

    for (i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    if (m == 1) {
        if (count(arr1, arr1 + n, arr2[0]) >= 1) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        return 0;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (arr2[i] == arr1[j]) {
                arr[k++] = j;
                break;
            }
        }
    }

    for (i = 0; i < m - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            f = 0;
            break;
        }
    }

    f ? cout << "YES" : cout << "NO";

    return 0;
}