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
    y = x1 - y1 * (a / b);

    return d;
}

void solve(int a, int b)
{
    int x, y, gcd;

    gcd = extended_euclid(a, b, x, y);

    cout << x << " " << y << " " << gcd << "\n";
}

void separate_numbers(char *s, int &a, int &b)
{
    int n = strlen(s);
    int i;

    for (i = 0; i < n; i++) {
        if (s[i] == ' ') {
            break;
        }
        else {
            a = a * 10 + (s[i] - '0');
        }
    }

    for (i = i + 1; i < n; i++) {
        b = b * 10 + (s[i] - '0');
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[100];

    while (scanf("%[^\n]%*c", s) != EOF) {
        int a = 0, b = 0;

        separate_numbers(s, a, b);

        solve(a, b);
    }

    return 0;
}