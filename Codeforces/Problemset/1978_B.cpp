#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, a, b, k, profit;

    cin >> n >> a >> b;

    if (a >= b) {
        profit = n * a;
    }
    else {
        k = b - a;
        if (k <= n) {
            profit = n * a + ((k * (k + 1)) / 2);
        }
        else {
            profit = n * a + ((k * (k + 1)) / 2);

            k = k - n;

            profit -= ((k * (k + 1)) / 2);
        }
    }

    cout << profit << "\n";
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