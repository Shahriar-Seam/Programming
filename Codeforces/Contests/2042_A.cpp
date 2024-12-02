#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;
    long long sum = 0, coins = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <int> ());

    for (i = 0; i < n; i++) {
        if (sum + v[i] > k) {
            coins = k - sum;

            break;
        }

        sum += v[i];
    }

    if (sum < k) {
        coins = k - sum;
    }

    cout << coins << "\n";
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