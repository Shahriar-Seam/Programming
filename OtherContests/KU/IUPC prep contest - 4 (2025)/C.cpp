#include <bits/stdc++.h>

using namespace std;

#define int long long

int sum_of_square(int n)
{
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

int sum_of_i(int n)
{
    return (n * (n + 1)) / 2;
}

void solve()
{
    int n, i, q, x, sum = 0;
    int a, b, c, cnt;

    cin >> n;
    
    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    cin >> q;

    while (q--) {
        cin >> x;

        if (n - x + 1 >= 6) {
            a = x * n;
            b = (x + 1) * (n - 1);
            c = (x + 2) * (n - 2);

            cnt = (n - x + 1) / 2;
            sum = 0;

            sum += ((a - 2 * b + c) / 2) * sum_of_square(cnt);
            sum += -((5 * a - 8 * b + 3 * c) / 2) * sum_of_i(cnt);
            sum += (3 * a - 3 * b + c) * cnt;

            if ((n - x + 1) % 2 == 1) {
                cout << sum_of_square(x - 1) + sum * 2 + (n - cnt) * (n - cnt) << "\n";
            }
            else {
                cout << sum_of_square(x - 1) + sum * 2 << "\n";
            }
        }
        else {
            sum = sum_of_square(x - 1);

            for (i = x; i <= n; i++) {
                sum += i * (n + x - i);
            }

            cout << sum << "\n";
        }
    }
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