#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n;

    for (k = 1; k <= n; k++) {
        cout << (k * k * (k * k - 1)) / 2 - 4 * (k - 1) * (k - 2) << "\n";
    }

    return 0;
}