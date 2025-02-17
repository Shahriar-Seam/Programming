#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <int> v(m);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    cout << n - m << "\n";

    for (i = 0, j = 1; i < m; i++) {
        while (j <= n && j < v[i]) {
            cout << j++ << " ";
        }

        j++;
    }

    while (j <= n) {
        cout << j++ << " ";
    }

    return 0;
}