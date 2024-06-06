#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, arr[3];
    int *max, *min;

    for (i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    max = max_element(arr, arr + 3);
    min = min_element(arr, arr + 3);

    cout << *min << " " << *max;

    return 0;
}