#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, b;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    while (m--) {
        cin >> b;

        cout << int(upper_bound(v.begin(), v.end(), b) - v.begin()) << " ";
    }

    return 0;
}