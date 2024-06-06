#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, arr[3], arr_og[3];

    for (i = 0; i < 3; i++) {
        cin >> arr_og[i];
        arr[i] = arr_og[i];
    }

    sort(arr, arr + 3);

    for (i = 0; i < 3; i++) {
        cout << arr[i] << endl;
    }

    cout << endl;
    
    for (i = 0; i < 3; i++) {
        cout << arr_og[i] << endl;
    }

    return 0;
}