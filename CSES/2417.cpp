#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

#define int long long

const int sz = 1e6 + 5;
vector <bool> marked(sz, true);
vector <int> freq(sz, 0), mu(sz, 1);

void sieve()
{
    int i, j;

    for (i = 2; i < sz; i++) {
        if (marked[i]) {
            for (j = i; j < sz; j += i) {
                marked[j] = false;
                mu[j] *= -1;
            }

            for (j = i * i; j < sz; j += i * i) {
                mu[j] = 0;
            }
        }
    }
}

int pairs(int n)
{
    return (n * (n - 1)) / 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, d, x = 0, i, count_d, total = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        x = max(x, it);

        freq[it]++;
    }

    for (d = 1; d <= x; d++) {
        for (count_d = 0, i = 1; i * d <= x; i++) {
            count_d += freq[i * d];
        }

        total += mu[d] * pairs(count_d);
    }

    cout << total << "\n";

    return 0;
}