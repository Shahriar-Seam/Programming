#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j = 0, k = 0, l, f, index = 0;
    long long total_skill = 0, temp = 0;

    vector <int> a, b;
    vector <long long> v;

    cin >> n >> m;

    vector <bool> status(m + n + 1, 0);

    for (i = 0; i < n + m + 1; i++) {
        cin >> f;

        a.push_back(f);
    }

    for (i = 0; i < n + m + 1; i++) {
        cin >> f;

        b.push_back(f);
    }

    for (i = 0; i < m + n; i++) {
        if ((a[i] >= b[i] && (j < n)) || (k == m)) {
            total_skill += a[i];

            status[i] = 1;

            j++;
        }
        else if ((b[i] >= a[i] && (k < m)) || (j == n)) {
            total_skill += b[i];

            k++;
        }
    }

    for (i = 0, j = 0; i < n + m + 1; i++) {
        if (a[i] >= b[i]) {
            j++;
        }

        if (j == n) {
            index = i;
        }
    }

    for (i = 0; i < m + n + 1; i++) {
        if (i == index) {
            temp = j = k = 0;

            for (l = 0; l < n + m + 1; l++) {
                if (l == index) {
                    continue;
                }
                else {
                    if ((a[l] >= b[l] && (j < n)) || (k == m)) {
                        temp += a[l];

                        j++;
                    }
                    else if ((b[l] >= a[l] && (k < m)) || (j == n)) {
                        temp += b[l];

                        k++;
                    }
                }
            }

            v.push_back(temp);
        }
        else if (status[i] == true) {
            v.push_back(total_skill - a[i] + a[m + n]);
        }
        else {
            v.push_back(total_skill - b[i] + b[m + n]);
        }
    }

    for (auto it : v) {
        cout << it << " ";
    }

    cout << "\n";
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