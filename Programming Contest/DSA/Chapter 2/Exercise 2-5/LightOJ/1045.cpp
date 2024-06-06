#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(0);

    int t, n, b, i;
    double base_n;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> n >> b;

        base_n = (n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0) / log10(b);

        cout << "Case " << i << ": " << max(1, (int) ceil(base_n)) << "\n";
    }

    return 0;
}