#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, i, j, k, one = 0, zero = 0, sum = 0;
    string s;
    stack <long long> st;

    cin >> n >> s;

    vector <pair <int, long long> > v(n, {0, 0});

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            st.push(i);
        }
        else {
            v[i].first = 1;
        }
    }

    for (i = n - 1; i > 0; i--) {
        if (s[i] == '1') {
            while (!st.empty() && st.top() > i) {
                sum += st.top() + 1;

                v[st.top()].first = 0;
                v[st.top()].second = 1;

                st.pop();
            }

            if (!st.empty()) {
                sum += st.top() + 1;

                v[st.top()].first = 0;
                v[st.top()].second = 1;
                v[i].first = 1;
                v[i].second = 1;

                st.pop();
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (v[i].first == 0 && v[i].second == 0) {
            zero++;
        }
        else if (v[i].first == 1 && v[i].second == 0) {
            one++;
        }
    }

    one = (one + 1) / 2;

    for (i = 0, j = 0; i < n; i++) {
        if (v[i].first == 0 && v[i].second == 0) {
            sum += i + 1;
        }
        if (v[i].first == 1 && v[i].second == 0 && j < one) {
            sum += i + 1;
            j++;
        }
    }

    // for (auto it : v) {
    //     cout << it.first << " " << it.second << "\n";
    // }
    // cout << "\n";

    cout << sum << "\n";
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