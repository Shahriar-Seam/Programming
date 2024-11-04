#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, k, i = 0;
    long long b, c, sum = 0;
    map <long long, long long> mp;
    vector <long long> v;

    cin >> n >> k;

    while (k--) {
        cin >> b >> c;

        mp[b] += c;
    }

    for (auto it : mp) {
        v.push_back(it.second);
    }

    sort(v.begin(), v.end());

    for (auto it = v.rbegin(); it != v.rend() && i < n; i++, it++) {
        sum += *it;
    }

    cout << sum << "\n";
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