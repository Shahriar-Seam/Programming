#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n;

    vector <int> v(n), p;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < 31 && p.size() < 3; i++) {
        for (j = 0; j < n; j++) {
            if ((binary_search(v.begin(), v.end(), v[j] - (1 << i))) && (binary_search(v.begin(), v.end(), v[j] + (1 << i)))) {
                p = {v[j] - (1 << i), v[j], v[j] + (1 << i)};

                break;
            }
        }
    }

    if (p.empty()) {
        for (i = 0; i < 31 && p.size() < 2; i++) {
            for (j = 0; j < n; j++) {
                if (binary_search(v.begin(), v.end(), v[j] + (1 << i))) {
                    p = {v[j], v[j] + (1 << i)};
    
                    break;
                }
            }
        }
    }

    if (p.empty()) {
        p = {v[0]};
    }

    cout << p.size() << "\n";

    for (auto it : p) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}