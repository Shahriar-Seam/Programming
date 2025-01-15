#include <bits/stdc++.h>

using namespace std;

#define int long long

int max_subarr_sum(vector <int> &v)
{
    int max_sum = 0LL, sum = 0LL, i;

    for (i = 0; i < v.size(); i++) {
        sum += v[i];

        max_sum = max(max_sum, sum);

        sum = max(sum, 0LL);
    }

    return max_sum;
}

void solve()
{
    int n, sum = 0LL, i, j;

    cin >> n;

    vector <int> v(n), pos, neg, new_v;

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        if (it < 0) {
            neg.push_back(it);
        }
        else if (it > 0) {
            pos.push_back(it);
        }
    }

    for (i = 0, j = 0; i < pos.size() && j < neg.size(); i++) {
        new_v.push_back(pos[i]);

        sum += pos[i];

        while (sum > 0 && j < neg.size()) {
            new_v.push_back(neg[j]);

            sum += neg[j];

            j++;
        }
    }

    for (i; i < pos.size(); i++) {
        new_v.push_back(pos[i]);
    }

    for (j; j < neg.size(); j++) {
        new_v.push_back(neg[j]);
    }

    cout << min({max({0LL, accumulate(v.begin(), v.end(), 0LL), *max_element(v.begin(), v.end())}), max_subarr_sum(new_v)}) << "\n";
}

int32_t main()
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