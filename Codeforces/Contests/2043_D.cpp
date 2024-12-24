#include <bits/stdc++.h>

using namespace std;

#define int long long

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

void solve()
{
    int l, r, g;
    int left, right;

    cin >> l >> r >> g;

    left = ((l + g - 1) / g) * g;
    right = (r / g) * g;

    while (right >= left) {
        if (GCD(left, right) != g) {
            right -= g;
        }
        else {
            break;
        }
    }

    if (left <= right) {
        cout << left << " " << right << "\n";
    }
    else {
        cout << "-1 -1\n";
    }
}

int32_t main()
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