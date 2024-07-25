#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, cnt = 0, i;

    cin >> n >> m;

    vector <int> v(m);

    for (auto &it : v) {
        cin >> it;
    }
    
    sort(v.begin(), v.end(), greater <int> ());

    while (v.size() > n) {
        int temp = v.back();

        v.pop_back();

        temp += v.back();

        v.pop_back();

        v.push_back(temp);
    }

    for (i = 0; i < n && i < m; i++) {
        if (v[i] >= m) {
            cnt++;
        }
    }

    cout << cnt << "\n";
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