#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}
 
int pow10(int p)
{
    int n = 1;
 
    while (p--) {
        n *= 10;
    }
 
    return n;
}

bool is_pow10(int n)
{
    if (n < 10) {
        return false;
    }

    while (n > 1) {
        if (n % 10) {
            return false;
        }

        n /= 10;
    }

    return true;
}

int digit_len(int n)
{
    int len = 0;

    while (n) {
        len++;

        n /= 10;
    }

    return len;
}

int separate(int n)
{
    while (n >= 10) {
        n /= 10;
    }

    return n;
}

int sum(int n)
{
    if (n < 10) {
        return (n * (n + 1)) / 2;
    }

    int d = digit_len(n) - 1, a = separate(n) * pow10(d), b = n - a;

    a = separate(n);

    if (is_pow10(n + 1)) {
        return sum(n / 10) * 10 + 45 * pow10(d);
    }
    else {
        return sum(pow10(d) - 1) * a + ((a * (a - 1)) / 2) * pow10(d) + a * (b + 1) + sum(b);
    }

    return 0;
}

void solve()
{
    int k, i = 1, c = 9, n, SUM = 0;
 
    cin >> k;
 
    while (k > i * c) {
        k -= i * c;
 
        i++;
 
        c *= 10;
    }
 
    n = pow10(i - 1) - 1 + ceil_div(k, i) - 1;

    string s = to_string(n + 1);

    k %= i;

    if (k == 0) {
        k = i;
    }

    for (i = 0; i < k; i++) {
        SUM += s[i] - '0';
    }

    cout << sum(n) + SUM << "\n";
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