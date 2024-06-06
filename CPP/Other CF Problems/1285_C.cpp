#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, a, b, f;

    cin >> x;

    for (a = 1; a * a <= x; a++) {
        if (x % a == 0 && lcm(a, x / a) == x) {
            f = a;
        }
    }

    cout << f << " " << x / f;

    return 0;
}