#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, max_id = 0;
    long long l = 0, r = 1e12 + 5, m, i, j, count;
    long long sum;
    double avg;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (v[i] > v[max_id]) {
            max_id = i;
        }
    }

    sum = accumulate(v.begin(), v.end(), 0);

    for (i = 0; i < 50; i++) {
        m = l + (r - l) / 2;

        avg = (sum + m) / (1.0 * n);

        for (j = 0, count = 0; j < n; j++) {
            if (j != max_id && v[j] < (avg / 2)) {
                count++;
            }
        }

        if (count > n / 2) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << (r == 1e12 + 5 ? -1 : r) << "\n";
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