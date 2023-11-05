#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, x, c, i, f, arr[10001];

    cin >> t;

    for (i = 10000; i > 0; i--) {
        arr[i] = i * i * i;
    }

    while (t--) {
        cin >> x;

        f = 0;
        c = ceil(cbrt(x));

        if (x == 1000000000000) {
            cout << "NO\n";
            continue;
        }

        for (i = 1; i <= c; i++) {
            if (find(arr + 1, arr + 10001, x - (i * i * i)) != arr + 10001) {
                f = 1;
                break;
            }
        }

        f ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}