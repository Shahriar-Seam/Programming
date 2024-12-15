#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, x = 1;
    set <int> s;

    cin >> n;

    vector <int> v(n), b;
    vector <bool> visited(n + 1, false);

    for (auto &it : v) {
        cin >> it;
    }

    b = v;

    for (i = 0; i < n; i++) {
        if (!visited[b[i]]) {
            visited[b[i]] = true;

            s.insert(b[i]);
        }
        else {
            while (s.find(x) != s.end()) {
                x++;
            }

            while (visited[x]) {
                x++;
            }
            
            b[i] = x;

            visited[x] = true;

            x++;
        }
    }

    for (auto it : b) {
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