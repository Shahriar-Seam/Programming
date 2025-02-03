#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, d = 0, k = 0, g;
    string s;
    map <pair <int, int>, int> mp;

    cin >> n >> s;

    for (auto c : s) {
        d += (c == 'D');
        k += (c == 'K');

        g = __gcd(d, k);

        mp[{d / g, k / g}]++;

        cout << mp[{d / g, k / g}] << " ";
    }

    cout << "\n";
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