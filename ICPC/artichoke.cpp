#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(8);

    double p, a, b, c, d;
    double mx = -1e18, current = 0, result = 0;
    int n, k;

    cin >> p >> a >> b >> c >> d >> n;

    for (k = 1; k <= n; k++) {
        current = p * (sin(a * k + b) + cos(c * k + d) + 2);

        result = max(result, mx - current);

        mx = max(mx, current);
    }

    cout << result << "\n";

    return 0;
}