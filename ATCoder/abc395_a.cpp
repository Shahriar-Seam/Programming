#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, f = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
            f = 0;
        }
    }

    cout << (f ? "Yes" : "No") << "\n";

    return 0;
}