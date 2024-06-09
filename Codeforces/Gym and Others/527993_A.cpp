#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int k, x;
    long long ans;

    cin >> k >> x;

    cout << (1LL * k * x) % 1000000007 << "\n";
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