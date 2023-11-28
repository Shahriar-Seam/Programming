#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, cnt = 0;

    cin >> n;

    arr = new int[n];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 1; i < n; i++) {
        if ((arr[i - 1] < 0 && arr[i] < 0) || (arr[i - 1] > 0 && arr[i] > 0)) {
            cnt++;
        }
    }

    cnt > 0 ? cout << cnt - 1 : cout << 0;

    return 0;
}