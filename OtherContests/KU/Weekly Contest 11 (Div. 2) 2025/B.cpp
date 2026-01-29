#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b = 1;

    cin >> n;

    a = n;

    while (a > 10) {
        a /= 10;
        b *= 10;
    }

    cout << n - b << b << "\n";

    return 0;
}