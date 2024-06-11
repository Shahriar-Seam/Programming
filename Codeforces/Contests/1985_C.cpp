#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, i, temp, cnt = 0;
    vector <long long> v, pre, v_sorted;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    v_sorted.push_back(v[0]);

    for (i = 1; i < n; i++) {
        v_sorted.push_back(max(v_sorted.back(), v[i]));
    }

    pre.push_back(v[0]);

    for (i = 1; i < n; i++) {
        pre.push_back(pre[i - 1] + v[i]);
    }

    for (i = 0; i < n; i++) {
        if (pre[i] - v[i] == v[i] || pre[i] - v_sorted[i] == v_sorted[i]) {
            cnt++;
        }
    }

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