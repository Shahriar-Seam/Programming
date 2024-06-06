#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, *m, f;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    m = min_element(arr, arr + n);

    f = count(arr, arr + n, *m);

    (f % 2 == 0) ? cout << "Unlucky" : cout << "Lucky";

    free(arr);

    return 0;
}