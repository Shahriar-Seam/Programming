#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long x, y, k, f = 0;
    set <long long> seen, bleh;
    vector <long long> meh;

    cin >> x >> y >> k;

    while (k > 0) {
        if (y - (x % y) <= k) {
            k -= (y - (x % y));
            x += y - (x % y);
            while (x % y == 0) {
                x /= y;
            }
        }
        else {
            x += k;
            k = 0;
        }

        meh.push_back(x);
        seen.insert(x);

        if (seen.find(x) != end(seen)) {
            k = (k % (y - (x % y)));

            cout << "k = " << k << "\n";
        }
    }

    for (auto it : meh) {
        // cout << it << " ";
    }

    cout << "" << x << "\n";
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