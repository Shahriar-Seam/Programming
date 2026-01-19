#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, k, i;
    string s;
    vector <pair <int, int> > v;
    
    cin >> n >> m >> k;

    vector <int> a(n), b(m), pref(k + 1, 0), cnt(k + 1, 0);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    cin >> s;

    for (i = 0; i < k; i++) {
        pref[i + 1] = pref[i] + (s[i] == 'R' ? 1 : -1);
    }

    for (i = 1; i <= k; i++) {
        v.push_back({pref[i], i});
    }

    b.push_back(-1e18);
    b.push_back(1e18);

    v.push_back({-1e18, -1});
    v.push_back({1e18, -1});

    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (auto &it : a) {
        auto nxt = lower_bound(b.begin(), b.end(), it);
        auto prv = nxt - 1;

        auto l = *prv - it;
        auto r = *nxt - it;

        auto p = lower_bound(v.begin(), v.end(), make_pair(l, -1LL));
        auto q = lower_bound(v.begin(), v.end(), make_pair(r, -1LL));

        if (p->first != l) {
            p = v.begin();
        }

        if (p->second != -1 && q->second != -1) {
            cnt[min(p->second, q->second)]--;
        }
        else if (p->second != -1) {
            cnt[p->second]--;
        }
        else if (q->second != -1) {
            cnt[q->second]--;
        }
    }

    for (i = 1; i <= k; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (i = 1; i <= k; i++) {
        cnt[i] += n;
    }

    for (i = 1; i <= k; i++) {
        cout << cnt[i] << " ";
    }

    cout << "\n";
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