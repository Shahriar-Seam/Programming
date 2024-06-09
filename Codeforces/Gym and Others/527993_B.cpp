#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, temp;
    int cnt = 0, count = 0;
    vector <int> v;

    cin >> n >> k;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    for (i = 1; i < n; i++) {
        v[i] -= v[i - 1];
    }

    for (i = 0; i < n; i++) {
        if (v[i] != 0) {
            cnt++;
        }
        else {
            count = max(count, cnt);

            cnt = 0;
        }
    }

    count = max(count, cnt);

    cout << count << "\n";
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