#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, l, r, min_sum = 0LL, sum = 0LL;
    int i, j;

    cin >> n >> l >> r;

    vector <int> v(n), temp1, temp2;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < r; i++) {
        temp1.push_back(v[i]);
    }

    for (i = l - 1; i < n; i++) {
        temp2.push_back(v[i]);
    }

    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());

    for (i = 0; i < r - l + 1; i++) {
        sum += temp1[i];
    }

    min_sum = sum;

    for (i = 0, sum = 0LL; i < r - l + 1; i++) {
        sum += temp2[i];
    }

    min_sum = min(min_sum, sum);

    cout << min_sum << "\n";
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