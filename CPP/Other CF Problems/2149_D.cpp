#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, cnt_a = 0, cnt_b = 0, mid = 0;
    string s;

    cin >> n >> s;

    vector <int> a, b;

    for (i = 0; i < n; i++) {
        if (s[i] == 'a') {
            a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }

    if (!a.empty()) {
        for (i = (a.size() / 2) - 1, j = 1, mid = a[a.size() / 2]; i >= 0; i--, j++) {
            cnt_a += mid - a[i] - j;
        }

        for (i = a.size() / 2 + 1, j = 1; i < a.size(); i++, j++) {
            cnt_a += a[i] - mid - j;
        }
    }

    if (!b.empty()) {
        for (i = (b.size() / 2) - 1, j = 1, mid = b[b.size() / 2]; i >= 0; i--, j++) {
            cnt_b += mid - b[i] - j;
        }

        for (i = b.size() / 2 + 1, j = 1; i < b.size(); i++, j++) {
            cnt_b += b[i] - mid - j;
        }
    }

    cout << min(cnt_a, cnt_b) << "\n";
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