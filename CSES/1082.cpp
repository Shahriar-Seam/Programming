#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int mod_inv2 = 5e8 + 4;

int sum(int a, int b)
{
    return (((((b - a + 1) % mod) * ((a + b) % mod) % mod) % mod) * mod_inv2) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int sigma = 0, at = 1, add_amt, last_same;

    cin >> n;

    while (at <= n) {
        add_amt = n / at;
        last_same = n / add_amt;

        sigma = (sigma + (add_amt * sum(at, last_same) % mod)) % mod;

        at = last_same + 1;
    }

    cout << sigma << "\n";

    return 0;
}