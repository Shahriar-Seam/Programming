#include <bits/stdc++.h>

using namespace std;

void to_bin(long long n, string &s)
{
    while (n > 0) {
        s.push_back('0' + n % 2);

        n /= 2;
    }
}

long long int binary_exponentiation(long long int b, long long int p)
{
    long long int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

long long getSetBitsFromOneToN(long long n)
{
    long long two = 2, ans = 0;
    long long temp = n;

    while (temp) {
        ans += (n / two) * (two >> 1);
        
        ans %= 998244353;
        
        if ((n & (two - 1)) > (two >> 1) - 1) {
            ans += (n & (two - 1)) - (two >> 1) + 1;
        }

        ans %= 998244353;

        two *= 2;
        temp /= 2;
    }

    return ans;
} // from GeeksForGeeks


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, zero = 0, meh;
    int i;
    string s;

    cin >> n >> m;

    to_bin(m, s);

    reverse(s.begin(), s.end());

    for (i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            zero += m / (binary_exponentiation(2, i - 1));
        }
    }

    if (m >= n) {
        cout << getSetBitsFromOneToN(n) - zero;
    }
    else {
        cout << getSetBitsFromOneToN(m) + getSetBitsFromOneToN((n - 1) % m) - zero;
    }

    return 0;
}