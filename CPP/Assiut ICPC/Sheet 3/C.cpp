#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > 0) {
            arr[i] = 1;
        }
        else if (arr[i] < 0) {
            arr[i] = 2;
        }
    }

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}