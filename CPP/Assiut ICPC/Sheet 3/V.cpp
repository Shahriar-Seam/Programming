#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, num, *arr, i;

    cin >> n >> m;

    arr = new int[m]();

    for (i = 0; i < n; i++) {
        cin >> num;

        arr[--num]++;
    }

    for (i = 0; i < m; i++) {
        cout << arr[i] << "\n";
    }

    delete arr;

    return 0;
}