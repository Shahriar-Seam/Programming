#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, m, i, l, r, cnt = 0;

    cin >> n >> m;

    vector <long long> a(n), b(n);
    map <long long, long long> mp_a, mp_b;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        a[i] %= m;
        b[i] %= m;

        mp_a[a[i]]++;
        mp_b[b[i]]++;
    }

    cnt = mp_a[0] * mp_b[0];


    for (auto it : mp_a) {
        cnt += it.second * mp_b[m - it.first];
    }

    cout << cnt << "\n";
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