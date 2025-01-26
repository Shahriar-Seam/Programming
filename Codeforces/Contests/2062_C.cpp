#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <int> diff(vector <int> v, int type)
{
    vector <int> d;
    int i;

    if (type == 0) {
        for (i = 0; i < v.size() - 1; i++) {
            d.push_back(v[i + 1] - v[i]);
        }
    }
    else {
        for (i = v.size() - 1; i > 0; i--) {
            d.push_back(v[i - 1] - v[i]);
        }
    }

    return d;
}

int dp(vector <int> v, map <vector <int>, int> &memo)
{
    if (v.size() == 1) {
        return v[0];
    }

    if (memo.find(v) == memo.end()) {
        memo[v] = max({dp(diff(v, 0), memo), dp(diff(v, 1), memo), accumulate(v.begin(), v.end(), 0LL)});
    }

    return memo[v];
}

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);
    map <vector <int>, int> memo;

    for (auto &it : v) {
        cin >> it;
    }

    cout << dp(v, memo) << "\n";
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