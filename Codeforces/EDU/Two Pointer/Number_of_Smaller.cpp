#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, count = 0;

    cin >> n >> m;

    vector <int> a(n), b(m), s(m, 0);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0, j = 0; i < m; i++) {
        while (j < n && a[j] < b[i]) {
            count++;
            j++;
        }

        s[i] = count;
    }

    for (auto it : s) {
        cout << it << " ";
    }

    return 0;
}