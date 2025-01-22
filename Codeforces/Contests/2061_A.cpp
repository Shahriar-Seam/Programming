#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, s = 0, point = -1;

    cin >> n;

    vector <int> v(n), e, o;

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        if (it % 2 == 0) {
            e.push_back(it);
        }
        else {
            o.push_back(it);
        }
    }

    cout << o.size() + (e.size() > 0 ? 1 : -1) << "\n";
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