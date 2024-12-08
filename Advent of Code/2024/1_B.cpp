#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, n = 1000, score = 0;

    vector <int> a(n), b(n);
    map <int, int> mp;

    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (auto it : b) {
        mp[it]++;
    }

    for (auto it : a) {
        score += it * mp[it];
    }

    cout << score << "\n";

    return 0;
}