#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp(int n)
{
    if (n % 2 == 1) {
        return 0;
    }

    return 1 << (n / 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << dp(n) << "\n";

    return 0;
}