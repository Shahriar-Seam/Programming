#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, max_val, min_val, l, r, temp;
    vector <int> v;

    cin >> t;

    while (t--) {
        cin >> n;

        max_val = 0;
        min_val = n + 1;

        for (i = 0; i < n; i++) {
            cin >> temp;

            v.push_back(temp);
        }

        if (v[0] != 1 && v[0] != n && v[n - 1] != 1 && v[n - 1] != n) {
            cout << 1 << " " << n << "\n";
        }
        else {
            min_val = 1;
            max_val = n;
            for (l = 0, r = n - 1; l < r; ) {
                if (max_val != v[l] && min_val != v[l] && max_val != v[r] && min_val != v[r]) {
                    break;
                }

                if (max_val == v[l]) {
                    l++;
                    max_val--;
                }
                else if (min_val == v[l]) {
                    l++;
                    min_val++;
                }
                else if (max_val == v[r]) {
                    r--;
                    max_val--;
                }
                else if (min_val == v[r]) {
                    r--;
                    min_val++;
                }
            }

            if (l < r) {
                cout << l + 1 << " " << r + 1 << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }

        v.clear();
    }

    return 0;
}