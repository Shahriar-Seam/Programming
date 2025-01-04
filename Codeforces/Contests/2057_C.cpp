#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r, i;
    int a, b, c;
    int num = 0;

    cin >> l >> r;

    for (i = 30; i >= 0; i--) {
        if ((l & (1 << i)) == (r & (1 << i))) {
            if (l & (1 << i)) {
                num += (1 << i);
            }
        }
        else {
            break;
        }
    }

    num += (1 << i);

    a = num - 1;
    b = num;
    c = num + 1;

    if (num < r) {
        cout << a << " " << b << " " << c << "\n";
    }
    else {
        cout << a - 1 << " " << a << " " << b << "\n";
    }
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