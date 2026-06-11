#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, l;
    int cnt_a, cnt_b, cnt_a_b;
    int cnt_0_a = 0, cnt_0_b = 0, cnt_0_a_b = 0;
    string a, b, a_b;

    cin >> n >> k >> a >> b;

    for (i = 0; i < n; i++) {
        a_b.push_back(a[i] == b[i] ? '0' : '1');

        cnt_0_a += a[i] == '0';
        cnt_0_b += b[i] == '0';
        cnt_0_a_b += a_b[i] == '0';
    }

    l = (1LL << k) + 1;

    cnt_a_b = l / 3;
    cnt_a = cnt_b = (l + 2) / 3;

    cout << cnt_a * cnt_0_a * (n - cnt_0_a) + cnt_b * cnt_0_b * (n - cnt_0_b) + cnt_a_b * cnt_0_a_b * (n - cnt_0_a_b) << "\n";
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