#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, count = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n / 2; i++) {
        if (v[i] == v[i + 1] || v[n - i - 1] == v[n - i - 2]) {
            swap(v[i + 1], v[n - i - 2]);
        }
    }

    for (i = 0; i < n - 1; i++) {
        count += (v[i] == v[i + 1]);
    }

    cout << count << "\n";
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