#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, x, i;
    set <long long> s;

    cin >> n >> x;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (s.find(v[i]) == s.end()) {
            s.insert(v[i]);
        }
        else {
            v[i] += x;
            
            while (s.find(v[i]) != s.end()) {
                v[i] += x;
            }

            s.insert(v[i]);
        }
    }

    i = 0;
    for (auto it : s) {
        if (it != i) {
            break;
        }
        else {
            i++;
        }
    }

    cout << i << "\n";
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