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

    for (i = 1, j = 0; i <= n; i++) {
        if (j >= m || i < v[j]) {
            cout << i << " ";
        }
        else {
            j++;
        }
    }

    return 0;
}