#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, k, i, max_cost = 0;
    long long bob = 0, alice = 0, temp, prev;

    cin >> n >> k;

    vector <long long> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        max_cost = max(max_cost, v[i]);
    }
    
    sort(v.begin(), v.end(), greater <int> ());

    for (i = 1; i < n; i += 2) {
        if (v[i - 1] - v[i] <= k) {
            k -= v[i - 1] - v[i];

            v[i] = v[i - 1];
        }
        else {
            v[i] += k;

            k = 0;
        }
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            alice += v[i];
        }
        else {
            bob += v[i];
        }
    }

    cout << alice - bob << "\n";
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