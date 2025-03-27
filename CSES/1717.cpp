#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int power(int n)
{
    if (n & 1) {
        return 1;
    }
    else {
        return -1;
    }
}

// Derangements
// from KACTL
int D(int n)
{
    if (n == 1) {
        return 0;
    }

    return (n * D(n - 1) - power(n)) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << D(n) << "\n";

    return 0;
}