#include <bits/stdc++.h>

using namespace std;

// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution

#define int long long
const int mod = 998244353;
const int mod_inv2 = 499122177;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, divs = 0, at = 1;
    int add_amt, last_same;

    cin >> n;

    while (at <= n) {
        add_amt = n / at;

        last_same = n / add_amt;

        divs = (divs + ((add_amt * (last_same - at + 1)) % mod)) % mod;

        at = last_same + 1;
    }

    n %= mod;

    cout << ((((((n * (n + 1) % mod) * mod_inv2) % mod) - divs) % mod) + mod) % mod << "\n";

    return 0;
}