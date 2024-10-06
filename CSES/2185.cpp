#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b)
{
    return b == 0 ? a : GCD(b, a % b);
}

long long LCM(long long a, long long b)
{
    return (a * b) / GCD(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;

    cin >> n >> m;

    long long sum = 0;
    long long temp;
    int i;

    vector <long long> v(m);

    for (i = 0; i < m; i++) {
        cin >> v[i];
    }

    long long mask = 0;
    long long l = 1;
    long long popcount = 0;

    for (mask = 1; mask < (1LL << m); mask++) {
        l = 1LL;
        popcount = 0;

        for (i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                popcount++;

                l = LCM(l, v[i]);

                if (l > 1e18) {
                    break;
                }
            }
        }

        if (popcount % 2 == 1) {
            sum += (n / l);
        }
        else {
            sum -= (n / l);
        }
    }

    cout << sum << "\n";

    return 0;
}