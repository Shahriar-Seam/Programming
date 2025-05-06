#include <bits/stdc++.h>

using namespace std;

#define int long long

int subarray_sum(vector <int> &v)
{
    int n = v.size(), i;
    int sum = 0, max_sum = *max_element(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        sum += v[i];

        max_sum = max(max_sum, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    return max_sum;
}

void solve()
{
    int n, k, i, max_sum = -2e9, count_0 = 0;
    string s;
    vector <vector <int> > bleh;

    cin >> n >> k >> s;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            temp.push_back(v[i]);
        }
        else {
            count_0++;

            if (temp.size() > 0) {
                bleh.push_back(temp);
            }

            temp.clear();
        }
    }

    if (temp.size() > 0) {
        bleh.push_back(temp);
    }

    for (auto &it : bleh) {
        max_sum = max(max_sum, subarray_sum(it));
    }

    if ((max_sum > k) || (count_0 == 0 && max_sum != k)) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        if (n == 1) {
            cout << k << "\n";

            return;
        }

        if (count_0 == 1) {
            int index;
            int l = -1e18, r = 1e18, m;
            int sum = 0;

            for (i = 0; i < n; i++) {
                if (s[i] == '0') {
                    index = i;

                    break;
                }
            }

            sum = subarray_sum(v);

            while (sum != k) {
                m = (l + r) / 2;

                v[index] = m;

                sum = subarray_sum(v);

                if (sum < k) {
                    l = m + 1;
                }
                else if (sum > k) {
                    r = m - 1;
                }
            }

            for (auto it : v) {
                cout << it << " ";
            }

            cout << "\n";
        }
        else {
            for (i = 0; i < n && count_0 > 1; i++) {
                if (s[i] == '0') {
                    v[i] = -1e18;
                    count_0--;
                }
            }

            int index;
            int l = -1e18, r = 1e18, m;
            int sum = 0;

            for (i = 0; i < n; i++) {
                if (s[i] == '0' && v[i] == 0) {
                    index = i;

                    break;
                }
            }

            sum = subarray_sum(v);

            while (sum != k) {
                m = (l + r) / 2;

                v[index] = m;

                sum = subarray_sum(v);

                if (sum < k) {
                    l = m + 1;
                }
                else if (sum > k) {
                    r = m - 1;
                }
            }

            for (auto it : v) {
                cout << it << " ";
            }

            cout << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}