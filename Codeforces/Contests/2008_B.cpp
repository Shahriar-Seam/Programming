#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, r, i, j;
    string s;
    char c;
    int f = 1;

    cin >> n >> s;

    r = sqrt(n);

    if (r * r == n) {
        for (i = 0; i < r; i++) {
            for (j = 0; j < r; j++) {
                c = s[i * r + j];

                if ((i == 0 || i == r - 1) && (c != '1')) {
                    f = 0;

                    break;
                }
                else if ((i > 0 && i < r - 1) && (j == 0 || j == r - 1) && c != '1') {
                    f = 0;

                    break;
                }
                else if ((i > 0 && i < r - 1) && (j > 0 && j < r - 1) && (c != '0')) {
                    f = 0;

                    break;
                }

            }

            if (!f) {
                break;
            }
        }
    }
    else {
        f = 0;
    }

    cout <<(f == 1 ? "YES" : "NO") << "\n";
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