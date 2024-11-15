#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, i, temp;

    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 1; i > 1; i--) {
        if (v[i] < v[i - 1]) {
            temp = v[i - 1] - v[i];

            v[i - 1] -= temp;
            v[i - 2] -= temp;
        }
    }

    for (i = 0; i < n - 2; i++) {
        if (v[i] > v[i + 1]) {
            temp = v[i] - v[i + 1];

            v[i + 1] += temp;
            v[i + 2] += temp;
        }
    }

    if (is_sorted(v.begin(), v.end())) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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