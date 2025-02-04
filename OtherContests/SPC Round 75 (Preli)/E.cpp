#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <int> s;
vector <int> pref;

void fill()
{
    int i;

    pref.resize(1e5 + 6, 0LL);

    for (i = 0; i < 1e5 + 5; i++) {
        s.push_back(i * i);
    }

    for (i = 0; i < 1e5 + 5; i++) {
        pref[i + 1] = pref[i] + s[i];
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << pref[n + 1] << "\n";
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