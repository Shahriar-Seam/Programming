#include <bits/stdc++.h>

using namespace std;

#define int long long

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
    y = x1 -  __int128_t(y1) * (a / b);

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

    while (true) {
        int n, t;

        cin >> n >> t;

        if (n == 0 && t == 0) {
            break;
        }

        while (t--) {
            int x, y, result;
            char c;

            cin >> x >> c >> y;

            if (c == '+') {
                result = (x + y) % n;
            }
            else if (c == '-') {
                result = ((x + n) - y) % n;
            }
            else if (c == '*') {
                result = (((__int128_t) x) * (__int128_t) y) % n;
            }
            else if (c == '/') {
                y = inverse_modulo(y, n);

                if (y == -1) {
                    result = -1;
                }
                else {
                    result = (((__int128_t) x) * (__int128_t) y) % n;
                }
            }

            cout << result << "\n";
        }
    }

    return 0;
}