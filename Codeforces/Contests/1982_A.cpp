#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x1, y1, x2, y2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    if ((x1 < y2 && y1 < x2)) {
        if (x1 < y1 && x2 < y2) {
            cout << "YES\n";
        }
        else if (x1 > y1 && x2 > y2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        cout << "YES\n";
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