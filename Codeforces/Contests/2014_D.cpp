#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, d, k, i, l, r, min_job = 1, max_job = 1;
    int b = 1, m = 1;
    int left, right, mid;
    int min_s = 1e8, max_s = 0;

    cin >> n >> d >> k;

    vector <int> v(n + 5, 0);
    vector <int> prefix(n + 5, 0);

    for (i = 0; i < k; i++) {
        cin >> l >> r;

        v[l] += 1;
        v[r + 1] -= 1;
    }

    for (i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }

    prefix[1] = v[1];

    for (i = 1; i <= n; i++) {
        prefix[i + 1] = prefix[i] + v[i + 1];
    }

    
    for (i = 1; i <= n - d + 1; i++) {
        if (prefix[i + d] - prefix[i - 1] < min_s) {
            min_s = prefix[i + d] - prefix[i - 1];

            min_job = i;
        }
        if (prefix[i + d] - prefix[i - 1] > max_s) {
            max_s = prefix[i + d] - prefix[i - 1];

            max_job = i;
        }
    }

    cout << "mm " << min_job << " " << max_job << "\n";
    cout << "mima " << min_s << " " << max_s << "\n";



    cout << "v ";
    for (i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";

    cout << "p ";
    for (i = 1; i <= n; i++) {
        cout << prefix[i] << " ";
    }

    cout << "\n";

    // cout << "bm " << b << " " << m << "\n";
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