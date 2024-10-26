#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;

    cin >> n >> k;

    vector <int> v(n), indices(n + 1, -1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        indices[v[i]] = i;
    }

    for (i = 0; i < k; i++) {
        
    }

    return 0;
}