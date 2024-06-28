#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n, i, max_size = 0;

    cin >> n;

    vector <long long> v(n), prefix(n + 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + v[i]) % 7;
    }

    vector <int> first_found(7, -1);

    for (i = 1; i <= n; i++) {
        if (first_found[prefix[i]] != -1) {
            max_size = max(max_size, i - first_found[prefix[i]]);
        }
        else {
            first_found[prefix[i]] = i;
        }
    }

    cout << max_size;

    return 0;
}