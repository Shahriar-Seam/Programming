#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, a, b, c, days = 0, rem = 0;

    cin >> n >> a >> b >> c;

    days = (n / (a + b + c)) * 3;
    
    rem = n - (n / (a + b + c)) * (a + b + c);

    if (rem > 0 && rem <= a) {
        days++;
    }
    else if (rem > 0) {
        days += 2;
    }

    cout << days << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}