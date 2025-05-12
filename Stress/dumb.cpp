#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {

    int n, i, j, len = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        set <int> s;

        for (j = i; j < n; j++) {
            s.insert(v[j]);

            len = max(len, s.size());

            if (s.size() < j - i + 1) {
                break;
            }
        }
    }

    cout << len << "\n";
}

    return 0;
}