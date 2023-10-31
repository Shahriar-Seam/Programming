#include <bits/stdc++.h>

#define yes cout << "YES\n"
#define no cout << "NO\n"

using namespace std;

int main()
{
    int t, arr[3], i;

    cin >> t;

    while (t--) {
        for (i = 0; i < 3; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + 3);

        if (arr[1] != arr[2]) {
            no;
        }
        else {
            if (arr[0] == arr[1]) {
                yes;
                cout << arr[0] << " " << arr[0] << " " << arr[0] << "\n";
            }
            else if (arr[0] >= 2) {
                yes;
                cout << arr[0] - 1 << " " << arr[0] << " " << arr[2] << "\n";
            }
            else {
                yes;
                cout << arr[0] << " " << arr[0] << " " << arr[2] << "\n";
            }
        }
    }

    return 0;
}