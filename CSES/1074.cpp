#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, cost = 0, i;

    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        cost += abs(v[i] - v[n / 2]);
    }

    cout << cost << "\n";

    return 0;
}