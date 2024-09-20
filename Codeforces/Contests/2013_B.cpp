#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, i;

    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 3; i >= 0; i--) {
        v[n - 2] -= v[i];
    }

    cout << v[n - 1] - v[n - 2] << "\n";
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