#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9 + 7)

long long int binary_exponentiation(long long int b, long long int p)
{
    long long int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p >>= 1;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    vector <int> n(t), k(t);

    for (auto &it : n) {
        cin >> it;
    }

    for (auto &it : k) {
        cin >> it;
    }

    for (i = 0; i < t; i++) {
        cout << binary_exponentiation(2, k[i]) << "\n";
    }

    return 0;
}