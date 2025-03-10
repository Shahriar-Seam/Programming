#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

// ax + by = gcd(a, b)
// returns gcd(a, b) and calculates x and y
int extended_euclid(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    int x1, y1;
    int d = extended_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

// x = a^-1 (mod m)
int inverse_modulo(int a, int m)
{
    int x, y;
    int g = extended_euclid(a, m, x, y);

    if (g != 1) {
        return -1;
    }

    return (x % m + m) % m;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n, i, count = 0;
    vector <int> fact;
    map <char, int> mp;

    cin >> s;

    n = s.size();

    fact.resize(n + 1, 1);

    for (i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    for (auto it : s) {
        mp[it]++;
    }

    count = fact[n];

    for (auto it : mp) {
        count = (count * inverse_modulo(fact[it.second], mod)) % mod;
    }

    cout << count << "\n";

    return 0;
}