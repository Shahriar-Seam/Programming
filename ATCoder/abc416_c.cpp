#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x, p, q, r, s, t;

    cin >> n >> k >> x;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (k == 1) {
        sort(v.begin(), v.end());

        cout << v[x - 1] << "\n";
    }
    else if (k == 2) {
        vector <string> ss;

        for (p = 0; p < n; p++) {
            for (q = 0; q < n; q++) {
                ss.push_back(v[p] + v[q]);
            }
        }

        sort(ss.begin(), ss.end());

        cout << ss[x - 1] << "\n";
    }
    else if (k == 3) {
        vector <string> ss;

        for (p = 0; p < n; p++) {
            for (q = 0; q < n; q++) {
                for (r = 0; r < n; r++) {
                    ss.push_back(v[p] + v[q] + v[r]);
                }
            }
        }

        sort(ss.begin(), ss.end());

        cout << ss[x - 1] << "\n";
    }
    else if (k == 4) {
        vector <string> ss;

        for (p = 0; p < n; p++) {
            for (q = 0; q < n; q++) {
                for (r = 0; r < n; r++) {
                    for (s = 0; s < n; s++) {
                        ss.push_back(v[p] + v[q] + v[r] + v[s]);
                    }
                }
            }
        }

        sort(ss.begin(), ss.end());

        cout << ss[x - 1] << "\n";
    }
    else if (k == 5) {
        vector <string> ss;

        for (p = 0; p < n; p++) {
            for (q = 0; q < n; q++) {
                for (r = 0; r < n; r++) {
                    for (s = 0; s < n; s++) {
                        for (t = 0; t < n; t++) {
                            ss.push_back(v[p] + v[q] + v[r] + v[s] + v[t]);
                        }
                    }
                }
            }
        }

        sort(ss.begin(), ss.end());

        cout << ss[x - 1] << "\n";
    }

    return 0;
}