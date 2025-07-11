#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i;

    cin >> n;

    deque <int> v(n), pos, neg;

    for (auto &it : v) {
        cin >> it;

        if (it > 0) {
            pos.push_back(it);
        }
        else {
            neg.push_back(it);
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater <> ());

    if (!pos.empty() && !neg.empty() && (abs((int) (pos.size() - neg.size())) > 1)) {
        cout << "No\n";

        return;
    }
    
    if (pos.empty() || neg.empty()) {
        sort(v.begin(), v.end());
    }
    else {
        v.clear();

        if (pos.size() > neg.size()) {
            v.push_back(pos.front());
            pos.pop_front();

            while (pos.size() > 0) {
                v.push_back(neg.front());
                v.push_back(pos.front());

                pos.pop_front();
                neg.pop_front();
            }
        }
        else {
            v.push_back(neg.front());
            neg.pop_front();

            while (pos.size() > 0) {
                v.push_back(pos.front());
                v.push_back(neg.front());

                pos.pop_front();
                neg.pop_front();
            }
        }
    }

    double r = v[1] * 1.0 / v[0];

    for (i = 1; i < n; i++) {
        if (abs(r - (v[i] * 1.0 / v[i - 1])) > 1e-9) {
            cout << "No\n";

            return;
        }
    }

    cout << "Yes\n";
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