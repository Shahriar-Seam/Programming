#include <bits/stdc++.h>

using namespace std;

#define int long long

int median(vector <int> &v)
{
    sort(v.begin(), v.end());

    return v[(v.size() - 1) / 2];
}

void solve()
{
    int n, k, sum = 0, i;

    cin >> n >> k;

    deque <int> v(n * k);
    vector <int> temp;

    for (auto &it: v) {
        cin >> it;
    }

    while (k--) {
        for (i = 0; i < (n - 1) / 2; i++) {
            temp.push_back(v.front());
            v.pop_front();
        }

        for (i = 0; i < n - (n - 1) / 2; i++) {
            temp.push_back(v.back());
            v.pop_back();
        }

        sum += median(temp);

        temp.clear();
    }

    cout << sum << "\n";
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