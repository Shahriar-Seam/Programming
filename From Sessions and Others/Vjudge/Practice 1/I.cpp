#include <bits/stdc++.h>

using namespace std;

int divisor(int n)
{
    int i;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }

    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m;

    cin >> t;

    while (t--) {
        cin >> n >> m;

        if (n == 1) {
            cout << "YES\n";
        }
        else if (divisor(n) > m) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}