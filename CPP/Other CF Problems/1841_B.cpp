#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, i, j, first_small = 0, first_small_index = 0;
    vector <int> q;
    vector <int> v;

    cin >> n;

    for (i = 0, j = 0; i < n; i++) {
        cin >> x;

        if (i == 0) {
            q.push_back(x);
            
            v.push_back(1);

            j++;
        }
        else {
            if (first_small == 1) {
                if (x <= q[0]) {
                    q.push_back(x);

                    v.push_back(1);

                    j++;
                }
                else {
                    v.push_back(0);
                }
            }
            else if (x >= q[j - 1]) {
                q.push_back(x);

                v.push_back(1);

                j++;
            }
            else if (x <= q[j - 1] && first_small == 0) {
                q.push_back(x);

                v.push_back(1);

                first_small = 1;
                first_small_index = i;
                j++;
            }
            else {
                v.push_back(0);
            }
        }
    }

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it;
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