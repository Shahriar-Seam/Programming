#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c, m, ans = 0;

    cin >> a >> b >> c;

    m = min({a, b, c});

    ans = m;

    a -= m;
    b -= m;
    c -= m;

    ans += ((a / 2) < c) ? (a / 2) : c;

    cout << ans;

    return 0;
}