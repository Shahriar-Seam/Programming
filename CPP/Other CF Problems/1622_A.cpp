#include <bits/stdc++.h>

#define yes cout << "YES\n"
#define no cout << "NO\n"

using namespace std;

int main()
{
    int t, arr[3];

    cin >> t;

    while (t--) {
        cin >> arr[0] >> arr[1] >> arr[2];

        sort (arr, arr + 3);

        if (arr[0] + arr[1] == arr[2]) {
            yes;
        }
        else if (((arr[0] == arr[1]) && (arr[2] % 2 == 0)) || ((arr[1] == arr[2]) && (arr[0] % 2 == 0))) {
            yes;
        }
        else {
            no;
        }
    }

    return 0;
}