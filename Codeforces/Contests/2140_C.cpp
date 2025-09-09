#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, pos_m = 2e9, pos_m_i, neg_m = -1, neg_m_i, i;
    int sum_a = 0, sum_b = 0, sum_c = 0, diff = -2e12;

    cin >> n;

    vector <int> v(n), pos, neg;
    vector <pair <int, int> > pp, nn;

    for (auto &it : v) {
        cin >> it;
    }

    if (n == 1) {
        cout << v[0] << "\n";

        return;
    }

    for (i = 0; i < n; i++) {
        if (i & 1) {
            if (v[i] > neg_m) {
                neg_m = v[i];

                neg_m_i = i;
            }

            sum_a -= v[i];

            nn.push_back({v[i], i});
        }
        else {
            if (v[i] < pos_m) {
                pos_m = v[i];

                pos_m_i = i;
            }

            sum_a += v[i];

            pp.push_back({v[i], i});
        }
    }

    for (i = 0; i < n; i++) {
        if (v[i] == pos_m) {
            pos.push_back(i);
        }

        if (v[i] == neg_m) {
            neg.push_back(i);
        }
    }

    swap(v[pos.front()], v[neg.back()]);

    for (i = 0; i < n; i++) {
        if (i & 1) {
            sum_b -= v[i];
        }
        else {
            sum_b += v[i];
        }
    }

    sum_c = sum_a;

    sum_a += n - 1 - (n % 2 == 0);

    sum_b += max({abs(pos.front() - neg.front()), abs(pos.front() - neg.back()), abs(pos.back() - neg.front()), abs(pos.back() - neg.back())});

    sort(nn.begin(), nn.end());

    for (auto &it : pp) {
        for (i = 0; i < nn.size(); i++) {
            diff = max(diff, nn[i].first - it.first + abs(nn[i].second - it.second));
        }
    }

    sum_c += diff;

    cout << max({sum_a, sum_b, sum_c}) << "\n";
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