#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i += 2) {
        sum += v[i + 1] - v[i];
    }

    cout << sum << "\n";

    return 0;
}