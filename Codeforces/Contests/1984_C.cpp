#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp;
    long long c = 0, sum = 0;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        sum += temp;
        c = c + temp;
        c = max({c, abs(c), abs(sum)});
    }

    cout << c << "\n";
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