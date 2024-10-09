#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, x, i;
    map <long long, int> mp;

    cin >> n >> x;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        mp[v[i]]++;
    }

    for (i = 0; i < n; i++) {
        if (mp[i] == 0) {
            break;
        }
        else if (mp[i] > 1) {
            mp[i + x] += mp[i] - 1;
            mp[i] = 1;
        }
    }

    cout << i << "\n";
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