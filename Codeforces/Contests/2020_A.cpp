#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, k, p, count = 0, temp_c;

    cin >> n >> k;

    if (k == 1 || n < k) {
        cout << n << "\n";

        return;
    }

    while (n > 0) {
        p = log(n) / log(k);

        if (n < k) {
            count += n;

            break;
        }

        if (n == 1) {
            count++;
            break;
        }

        if (pow(k, p + 1) <= n) {
            p++;
        }

        temp_c = n / pow(k, p);

        count += temp_c;

        n -= temp_c * pow(k, p);
    }

    cout << count << "\n";
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