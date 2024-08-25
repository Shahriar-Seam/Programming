#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);
    
    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    cout << v[n / 2] << "\n";
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