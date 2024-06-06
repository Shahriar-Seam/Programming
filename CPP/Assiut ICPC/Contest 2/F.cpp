#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, max = 0, c, i;

    cin >> t;

    while (t--) {
        cin >> n;

        c = 0;

        while (n % 2 != 1) {
            c++;
            n /= 2;
        }

        if (c > max) {
            max = c;
        }
    }

    cout << max;

    return 0;
}