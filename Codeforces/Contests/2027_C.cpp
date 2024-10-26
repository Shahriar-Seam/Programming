#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    long long count1 = 0, count2 = 0;

    cin >> n;

    vector <long long> v(n + 1, 0);

    count1 = count2 = n;

    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (i = n; i >= 1; i--) {
        if (v[i] == count1 + 1 - i) {
            count1 += i - 1;
        }
    }

    for (i = 1; i <= n; i++) {
        if (v[i] == count1 + 1 - i) {
            count1 += i - 1;
        }
    }

    for (i = 1; i <= n; i++) {
        if (v[i] == count2 + 1 - i) {
            count2 += i - 1;
        }
    }

    for (i = n; i >= 1; i--) {
        if (v[i] == count2 + 1 - i) {
            count2 += i - 1;
        }
    }

    cout << max(count1, count2) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}