#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, a, b, c, d, two = 0, three = 0, four = 0, f = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }
    
    sort(v.begin(), v.end());

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        if (it.second >= 2) {
            if (two == 0) {
                a = it.first;
                b = it.first;
            }
            else {
                c = it.first;
                d = it.first;
            }

            two++;
        }

        if (it.second == 3) {
            three++;
        }

        if (it.second >= 4) {
            a = it.first;
            b = it.first;
            c = it.first;
            d = it.first;

            four++;
        }
    }

    if (four || two >= 2) {
        cout << a << " " << b << " " << c << " " << d << "\n";

        return;
    }

    if (!two) {
        cout << "-1\n";

        return;
    }
    
    for (i = 1; i < n; i++) {
        if (v[i - 1] == v[i]) {
            c = v[i];

            for (j = 0; j < n; j++) {
                if (j != i - 1 && j != i) {
                    b = v[j];
                    
                    auto it = upper_bound(v.begin(), v.end(), b - 2 * c);

                    if (it != v.end() && (it - v.begin() != j)) {
                        a = *it;

                        if (((a == c || b == c) && a != b) && three) {
                            // valid;
                            f = 1;

                            cout << a << " " << c << " " << c << " " << b << "\n";

                            return;
                        }
                        else if (a != c && b != c) {
                            // valid
                            f = 1;

                            cout << a << " " << c << " " << c << " " << b << "\n";

                            return;
                        }
                    }
                }
            }
        }
    }

    cout << "-1\n";
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