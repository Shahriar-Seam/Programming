#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, l, r, i, sum;

    cin >> t;

    while (t--) {
        cin >> l >> r;

        for (i = l, sum = 0; i <= r; i++) {
            sum += i;
        }

        cout << sum << "\n";
    }

    return 0;
}