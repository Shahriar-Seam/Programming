#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, count = 1;
    map <int, int> x, y;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }
    
    cin >> m;

    vector <int> c(m), d(m);

    for (auto &it : c) {
        cin >> it;
    }

    for (auto &it : d) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        x[a[i]] = b[i];
    }

    for (i = 0; i < m; i++) {
        y[c[i]] = d[i];
    }

    for (auto &it : y) {
        if (x[it.first] < it.second) {
            count = 0;
        }
    }

    for (auto &it : x) {
        if (it.second > y[it.first]) {
            count = (count * 2) % mod;
        }
    }

    cout << count << "\n";

    return 0;
}