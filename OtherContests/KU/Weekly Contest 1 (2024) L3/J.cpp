#include <bits/stdc++.h>

using namespace std;

vector <long long> v(16, 0);

void solve()
{
    long long n, i, j, k;

    cin >> n;

    for (i = 15; v[i] > n; i--);

    for (i; i >= 0; i--) {
        for (j = 0, k = 0; j <= 10; j++) {
            if (j == 4) {
                k = 1;

                continue;
            }

            if ((j - k) * v[i] == n) {
                cout << j;

                n -= (j - k) * v[i];

                break;
            }
            else if ((j - k) * v[i] > n) {
                if (j == 5) {
                    cout << 3;
                }
                else {
                    cout << j - 1;
                }

                n -= (j - k - 1) * v[i];

                break;
            }
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    v[0] = 1;
    v[1] = 9;

    for (int i = 2; i < 16; i++) {
        v[i] = v[i - 1] * 9;
    }

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}