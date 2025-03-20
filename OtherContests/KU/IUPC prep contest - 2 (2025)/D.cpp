#include <bits/stdc++.h>

using namespace std;

double binary_exponentiation(double b, int p)
{
    double result = 1.0;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(15);

    int n, m;
    double sum = 0;
    int i;

    cin >> m >> n;

    for (i = 1; i < m; i++) {
        sum += binary_exponentiation((double) i / m, n);
    }

    cout << m - sum << "\n";

    return 0;
}