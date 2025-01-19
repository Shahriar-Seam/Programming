#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c, d, e, ans = 1;

    cin >> a >> b >> d >> e;

    c = a + b;
    
    ans = (a + b == c) + (b + c == d) + (c + d == e);

    c = d - b;

    ans = max(ans, (a + b == c) + (b + c == d) + (c + d == e));

    c = e - d;

    ans = max(ans, (a + b == c) + (b + c == d) + (c + d == e));

    cout << ans << "\n";
}

int main()
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