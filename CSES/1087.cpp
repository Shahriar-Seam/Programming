#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, dna = "ACGT";
    map <int, int> mp;

    cin >> s;

    for (auto &c : s) {
        mp[c]++;

        if (mp.size() == 4) {
            cout << c;

            mp.clear();
        }
    }

    for (auto &c : dna) {
        if (!mp[c]) {
            cout << c << "\n";

            break;
        }
    }

    return 0;
}