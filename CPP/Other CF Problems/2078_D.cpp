#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, l = 1, r = 1, extra = 0;
    int a, b;
    int temp1, temp2;
    int people = 0;
    char c, d;

    cin >> n;

    while (n--) {
        cin >> c >> a >> d >> b;

        if (c == '+') {
            temp1 = extra + a + l;
        }
        else if (c == 'x') {
            temp1 = (l + extra) * a;
        }

        if (d == '+') {
            temp2 = extra + b + r;
        }
        else if (d == 'x') {
            temp2 = (r + extra) * b;
        }

        if (temp1 >= temp2) {
            l += extra;

            extra = temp1 - l;

            if (d == '+') {
                extra += b;

                people = l + r + extra;
            }
            else if (d == 'x') {
                extra += r * (b - 1);

                people = l + r * b + extra;
            }
        }
        else {
            r += extra;

            extra = temp2 - r;

            if (c == '+') {
                extra += a;

                people = l + r + extra;
            }
            else if (c == 'x') {
                extra += l * (a - 1);

                people = l * a + r + extra;
            }
        }

        cout << temp1 << " " << temp2 << " " << l << " " << r << " " << extra << "\n";

    }

    cout << people << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}