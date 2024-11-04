#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    set <long long> s;

    cin >> n;

    vector <long long> v(n), f(n, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        auto it = s.find(v[i]);
        long long temp = v[i];

        while (it != s.end()) {
            s.erase(it);
            temp *= 2;
            it = s.find(temp);
        }

        s.insert(temp);

        f[i] = s.size();
    }

    for (auto it : f) {
        cout << it << " ";
    }

    cout << "\n";
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