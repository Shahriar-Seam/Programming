#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j, min_h = INT_MAX;

    cin >> n >> k;

    vector <int> v(n), prefix(n + 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = 0; i + k <= n; i++) {
        if (prefix[i + k] - prefix[i] < min_h) {
            min_h = prefix[i + k] - prefix[i];
            j = i;
        }
    }

    cout << j + 1;

    return 0;
}