#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, x = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        x ^= v[i];
    }

    for (i = 0; i < n; i++) {
        cout << (x ^ v[i]) << " ";
    }

    return 0;
}