#include <bits/stdc++.h>

using namespace std;

#define int long long

int l_value;

void recurse(int l, int r, int k)
{
    int m = (l + r) / 2;

    if (r - l + 1 < k) {
        return;
    }

    if (((r - l + 1) % 2) == 0) {
        int temp = r - l + 1;
        int count = 0;

        while (temp % 2 == 0) {
            temp /= 2;
            count++;
        }

        temp = 1LL << count;

        // int k = r / 

        recurse(l, m, k);
        recurse(m + 1, r, k);
    }
    else {
        l_value += m;


        recurse(l, m - 1, k);
        recurse(m + 1, r, k);
    }
}

void solve()
{
    int n, k, i, j;
    l_value = 0;

    cin >> n >> k;
    
    // need to implement the case with gaps
    for (i = 0; (1 << i) < n; i++) {
        if (n & (1 << i)) {
            int div = n / (1 << i);

            cout << div << " ";

            if ((i > 0) && (n & (1 << (i - 1)))) {
                for (j = (1 + div) / 2; j <= n; j += 3 * div) {
                    cout << j << " ";
                    
                    l_value += j;

                    l_value += j + div + 1;
                }
            }
            else {
                for (j = (1 + div) / 2; j <= n; j += div) {
                    l_value += j;
                }
            }

            cout << l_value << "\n";
        }
    }

    cout << l_value << "\n";
}

void test()
{
    int t = 55, n, k, i;

    // cin >> t;

    for (n = 1; n <= t; n++) {
        // cin >> n;

        cout << n << ": ";

        for (i = 1; i <= n; i++) {
            l_value = 0;

            recurse(1, n, i);

            cout << l_value << " ";
        }

        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // test();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}