#include <bits/stdc++.h>

#define yes cout << "YES\n"
#define no cout << "NO\n"

using namespace std;

int main()
{
    int t, n, x, *arr, i, odd, even;

    cin >> t;

    while (t--) {
        cin >> n >> x;

        arr = new int[n]();
        odd = even = 0;

        for (i = 0; i < n; i++) {
            cin >> arr[i];

            (arr[i] & 1) ? odd++ : even++;
        }

        if (odd >= x && even >= 1) {
            yes;
        }
        else if (even == 0 && x % 2 == 0) {
            no;
        }
        else if (even >= x && odd >= 1) {
            yes;
        }
        else if (odd + even == x && odd % 2 != 0) {
            yes;
        }
        else if(odd + even > x && odd >= 1){
            yes;
        }
        else {
            no;
        }

        delete[] arr;
    }

    return 0;
}