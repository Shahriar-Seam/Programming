#include <bits/stdc++.h>

using namespace std;

bool beautiful(int n)
{
    int k;

    for (k = 1; ; k++) {
        if (((1 << k) - 1) * (1 << (k - 1)) == n) {
            return true;
        }
        else if (((1 << k) - 1) * (1 << (k - 1)) > n) {
            break;
        }
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, d = 1;

    cin >> n;

    for (i = 1; i <= n; i++) {
        if ((n % i == 0) && (beautiful(i))) {
            d = i;
        }
    }

    cout << d << "\n";

    return 0;
}