#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <__int128_t> intervals;

void fill()
{
    int i, d = 1;

    for (i = 1; (__int128_t) i * 9 * d <= (__int128_t) 1e20; i++) {
        intervals.push_back(i * 9 * d);

        d *= 10;
    }
}

void solve()
{
    int k;

    cin >> k;

    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}