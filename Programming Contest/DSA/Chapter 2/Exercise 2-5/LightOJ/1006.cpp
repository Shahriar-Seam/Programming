#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 10000007

void solve(int t)
{
    ll n, i, temp;
    vector <ll> v;

    for (i = 0; i < 6; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    cin >> n;

    for (int i = 6; i <= n; i++) {
        v.push_back((v[i - 1] % mod) + (v[i - 2] % mod) + (v[i - 3] % mod) + (v[i - 4] % mod) + (v[i - 5] % mod) + (v[i - 6] % mod));
    }

    cout << "Case " << t << ": " << v[n] % mod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cases;

    cin >> cases;

    for (t = 1; t <= cases; t++) {
        solve(t);
    }

    return 0;
}