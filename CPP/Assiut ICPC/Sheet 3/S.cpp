#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, mn, *arr, x, i;
    int *f = NULL;

    cin >> n >> m;

    mn = m * n;

    arr = (int *) malloc(sizeof(int) * mn);

    for (i = 0; i < mn; i++) {
        cin >> arr[i];
    }

    cin >> x;

    f = find(arr, arr + mn, x);

    if (*f == x) {
        cout << "will not take number";
    }
    else {
        cout << "will take number";
    }

    return 0;
}