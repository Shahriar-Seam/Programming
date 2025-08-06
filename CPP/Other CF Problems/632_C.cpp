#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), [&] (string a, string b) {
        return a + b < b + a;
    });

    for (auto &it : v) {
        cout << it;
    }

    cout << "\n";

    return 0;
}