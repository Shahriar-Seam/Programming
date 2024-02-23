#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i;
    long long sum = 0;
    string l, r;

    cin >> l >> r;

    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());

    n = min(l.size(), r.size());
    m = max(l.size(), r.size());

    if (l.size() < r.size()) {
        for (i = n; i < m; i++) {
            l.push_back('0');
        }
    }
    else {
        for (i = n; i < m; i++) {
            r.push_back('0');
        }
    }

    for (i = 0; i < l.size(); i++) {
        sum += 1LL * abs((l[i] - '0') - (r[i] - '0'));

        cout << sum << " ";
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