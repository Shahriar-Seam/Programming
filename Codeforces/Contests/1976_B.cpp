#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 0;
    long long cnt = 1, additional = INT_MAX, bn;

    cin >> n;

    vector <int> a(n), b(n + 1);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    bn = b[n];

    b.pop_back();

    for (i = 0; i < n; i++) {
        cnt += abs(a[i] - b[i]);

        if (f == 0 && abs(bn - a[i]) < abs(bn - additional)) {
            additional = a[i];
        }

        if (bn >= min(a[i], b[i]) && bn <= max(a[i], b[i])) {
            f = 1;
            additional = bn;
        }
    }

    cnt += 1LL * min({abs(*max_element(a.begin(), a.end()) - bn), abs(bn - *min_element(a.begin(), a.end())), abs(additional - bn), abs(*max_element(b.begin(), b.end()) - bn), abs(bn - *min_element(b.begin(), b.end()))});

    cout << cnt << "\n";
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