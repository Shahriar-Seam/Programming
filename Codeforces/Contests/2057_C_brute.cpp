#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r;
    int a, b, c;
    int i, j, k;
    int max_xor = 0;

    cin >> l >> r;

    for (i = l; i <= r; i++) {
        for (j = i + 1; j <= r; j++) {
            for (k = j + 1; k <= r; k++) {
                if (((i ^ j) + (j ^ k) + (k ^ i)) > max_xor) {
                    max_xor = ((i ^ j) + (j ^ k) + (k ^ i));
                }
            }
        }
    }

    for (i = l; i <= r; i++) {
        for (j = i + 1; j <= r; j++) {
            for (k = j + 1; k <= r; k++) {
                if (((i ^ j) + (j ^ k) + (k ^ i)) == max_xor) {
                    cout << i << " " << j << " " << k << " ";
                    cout << ((i ^ j) + (j ^ k) + (k ^ i)) << "\n";
                }
            }
        }
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