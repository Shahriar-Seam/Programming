#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, first, second, coins, n, m;

    cin >> t;

    while (t--) {
        cin >> first >> second;
        cin >> n >> m;

        coins = min(first * (m * (n / (m + 1))) + min(first, second) * (n % (m + 1)), min(first, second) * n);

        cout << coins << "\n";
    }

    return 0;
}