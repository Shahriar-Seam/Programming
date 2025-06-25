#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int i, j, count, mutations = 1e9;

    cin >> s >> t;

    for (i = 0; i < s.size() - t.size() + 1; i++) {
        count = 0;

        for (j = 0; j < t.size(); j++) {
            count += (s[i + j] != t[j]);
        }

        mutations = min(mutations, count);
    }

    cout << mutations << "\n";

    return 0;
}