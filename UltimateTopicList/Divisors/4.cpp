#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    set <int> s;

    cin >> n;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            s.insert(i);
            s.insert(n / i);
        }
    }

    cout << s.size() << "\n";
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