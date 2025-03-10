#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, max_f = 0;
    string s;
    map <char, int> mp_a, mp_b;

    cin >> n >> s;

    for (auto it : s) {
        mp_b[it]++;
    }

    max_f = mp_b.size();

    for (auto c : s) {
        mp_a[c]++;
        mp_b[c]--;

        if (mp_b[c] == 0) {
            mp_b.erase(c);
        }

        max_f = max(max_f, mp_a.size() + mp_b.size());
    }

    cout << max_f << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}