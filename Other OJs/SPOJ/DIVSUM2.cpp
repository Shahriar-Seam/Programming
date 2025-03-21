#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull modmul(ull a, ull b, ull M)
{
    ll ret = a * b - M * ull(1.L / M * a * b);

    return ret + M * (ret < 0) - M * (ret >= (ll) M);
}

ull modpow(ull b, ull e, ull mod)
{
    ull ans = 1;

    for (; e; b = modmul(b, b, mod), e /= 2) {
        if (e & 1) {
            ans = modmul(ans, b, mod);
        }
    }

    return ans;
}

// Miller Rabin
bool isPrime(ull n)
{
    if (n < 2 || n % 6 % 4 != 1) {
        return (n | 1) == 3;
    }

    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n - 1);
    ull d = n >> s;

    for (ull a : A) {
        ull p = modpow(a % n, d, n);
        ull i = s;

        while (p != 1 && p != n - 1 && a % n && i--) {
            p = modmul(p, p, n);
        }

        if (p != n - 1 && i != s) {
            return 0;
        }
    }

    return 1;
}

ull pollard_rho(ull n) {
    auto f = [n](ull x) {
        return modmul(x, x, n) + 2;
    };

    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;

    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) {
            x = ++i;
            y = f(x);
        }
        if ((q = modmul(prd, max(x, y) - min(x, y), n))) {
            prd = q;
        }

        x = f(x), y = f(f(y));
    }

    return __gcd(prd, n);
}

vector <ull> factor(ull n) {
    if (n == 1) {
        return {};
    }
    if (isPrime(n)) {
        return {n};
    }

    ull x = pollard_rho(n);

    auto l = factor(x), r = factor(n / x);

    l.insert(l.end(), begin(r), end(r));

    return l;
}

ull sum_of_divisors(ull n)
{
    ull sum = 1, temp;

    vector <ull> facts = factor(n);
    map <ull, ull> factors;

    for (auto it : facts) {
        factors[it]++;
    }

    for (auto it : factors) {
        temp = 1;

        while (it.second > 0) {
            temp += modpow(it.first, it.second, 1e18);

            it.second--;
        }

        sum *= temp;
    }

    sum -= n;

    return sum;
}

void solve()
{
    ull n;

    cin >> n;

    cout << sum_of_divisors(n) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}