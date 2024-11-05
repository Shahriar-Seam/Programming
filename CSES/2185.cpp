#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;

    cin >> n >> m;

    long long sum = 0;
    long long temp;
    long long i;

    vector <long long> v(m);

    for (i = 0; i < m; i++) {
        cin >> v[i];
    }

    long long mask = 0;
    long long product = 1;
    long long popcount = 0;

    for (mask = 1; mask < (1LL << m); mask++) {
        product = 1LL;
        popcount = 0;

        for (i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                popcount++;

                product *= v[i];

                if (product > n) {
                    break;
                }
            }
        }

        if (popcount % 2 == 1) {
            sum += n / product;
        }
        else {
            sum -= n / product;
        }
    }

    cout << sum << "\n";

    return 0;
}