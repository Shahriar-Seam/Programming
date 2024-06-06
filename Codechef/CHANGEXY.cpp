#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, k, cnt = 0;

    cin >> a >> b >> k;

    if (a * k > b || k == 1) {
        cout << b - a + 1 << "\n";

        return;
    }

    while (a != b && b >= a) {
        if (b % k == 0) {
            b /= k;

            cnt++;
        }
        
        if (a * k > b) {
            cnt += b - a;

            a = b;
        }

        if (a * k < b) {
            a *= k;

            cnt++;
        }
    }

    cout << cnt << "\n";
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