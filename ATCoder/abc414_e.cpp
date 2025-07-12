#include <bits/stdc++.h>

using namespace std;

// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution

#define int long long
const int mod = 998244353;
const int mod_inv2 = 499122177;

// sums n / 1 + n / 2 + n / 3 + ... + n / n
// O(sqrt(n))
int sum_n_by_k(int n, int mod = mod)
{
    int sum = 0, at = 1;
    int add_amt, last_same;

    while (at <= n) {
        add_amt = n / at;

        last_same = n / add_amt;

        sum = (sum + ((add_amt * (last_same - at + 1)) % mod)) % mod;

        at = last_same + 1;
    }

    return sum;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, divs;

    cin >> n;

    divs = sum_n_by_k(n);

    n %= mod;

    cout << ((((((n * (n + 1) % mod) * mod_inv2) % mod) - divs) % mod) + mod) % mod << "\n";

    return 0;
}