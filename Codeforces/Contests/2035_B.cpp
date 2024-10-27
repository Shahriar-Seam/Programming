#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, odd_sum = 0, even_sum = 0;
    string s;

    cin >> n;

    for (i = 0; i < n; i++) {
        s += '3';
    }

    if (n == 1 || n == 3) {
        cout << -1 << "\n";
    }
    else {
        s[n - 1] = '6';
        s[n - 2] = '6';

        if (n >= 4) {
            if (n % 2 == 1) {
                s[n - 4] = '6';
            }
        }

        cout << s << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}