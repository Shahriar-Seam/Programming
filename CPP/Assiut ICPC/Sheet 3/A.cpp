#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, *arr, sum = 0, i;

    cin >> n;

    arr = (long long *) malloc(sizeof(long long) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sum = accumulate(arr, arr + n, sum);

    cout << abs(sum);

    return 0;
}