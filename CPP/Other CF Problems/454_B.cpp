#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }
    
    v.push_back(v[0]);

    for (i = 1; i <= n; i++) {
        if (v[i] < v[i - 1]) {
            count++;
        }
    }

    if (count >= 2) {
        cout << -1 << "\n";
    }
    else {
        count = 0;

        for (i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                count = n - i;

                break;
            }
        }

        cout << count << "\n";
    }

    return 0;
}