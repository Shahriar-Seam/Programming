#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, pairs = 0;
    map <pair <int, int>, map <int, int> > mp_f, mp_b, mp_m;
    map <tuple <int, int, int>, int> mp_mm;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n - 2; i++) {
        mp_f[{v[i], v[i + 1]}][v[i + 2]]++;
        mp_b[{v[i + 1], v[i + 2]}][v[i]]++;
        mp_m[{v[i], v[i + 2]}][v[i + 1]]++;
    }

    for (auto it : mp_f) {   
        if (it.second.size() > 1) {
            int temp = 1;

            for (auto jt : it.second) {
                temp *= jt.second;
            }

            pairs += temp;
        }
    }
    
    for (auto it : mp_b) {   
        if (it.second.size() > 1) {
            int temp = 1;

            for (auto jt : it.second) {
                temp *= jt.second;
            }

            pairs += temp;
        }
    }

    for (auto it : mp_m) {   
        if (it.second.size() > 1) {
            int temp = 1;

            for (auto jt : it.second) {
                temp *= jt.second;
            }

            pairs += temp;
        }
    }

    cout << pairs << "\n";
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