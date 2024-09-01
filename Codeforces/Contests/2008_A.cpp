#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, rem;

    cin >> a >> b;

    if (a % 2 == 0) {
        if (b % 2 == 0) {
            cout << "YES\n";
        }
        else if (a >= 2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        cout << "NO\n";
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