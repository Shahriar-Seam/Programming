#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, s;
    string ss;
    int empty, partial = 0, ambiverts = 0, count = 0;

    cin >> n >> x >> s >> ss;

    empty = x;

    for (auto &c : ss) {
        if (c == 'I') {
            if (empty) {
                empty--;
                partial += s - 1;

                count++;
            }
        }
        else if (c == 'A') {
            if (partial) {
                partial--;
                ambiverts++;

                count++;
            }
            else if (empty) {
                empty--;
                partial += s - 1;
                
                count++;
            }
        }
        else if (c == 'E') {
            if (partial) {
                partial--;

                count++;
            }
            else if (empty && ambiverts) {
                empty--;
                ambiverts--;
                partial += s - 1;

                count++;
            }
        }
    }

    cout << count << "\n";
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