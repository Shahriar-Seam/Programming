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
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;

    auto f = [&](ull x) {
        return modmul(x, x, n) + i;
    };

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

void solve()
{
    ull n;

    cin >> n;

    vector <ull> factors = factor(n);

    sort(factors.begin(), factors.end());

    cout << factors.size() << " ";
    for (auto it : factors) {
        cout << it << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}