#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp, pre, post, max = 0, count = 0;
    vector <int> a, b;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        a.push_back(temp);
    }

    for (i = 1; i < n; i++) {
        b.push_back(__gcd(a[i], a[i - 1]));
    }

    if (is_sorted(b.begin(), b.end())) {
        cout << "YES\n";

        return;
    }
    else {
        pre = __gcd(a[0], a[1]);

        for (i = 2; i < n - 2; i++) {
            post = __gcd(a[i], a[i + 1]);
            temp = __gcd(a[i], a[i - 1]);

            // cout << pre << " " << temp << " " << post << "\n";

            if (temp < pre) {
                if (pre > post) {
                    count++;
                }
            }

            pre = temp;
        }

        cout << "heh" << count << "\n";
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