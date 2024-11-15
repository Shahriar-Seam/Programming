#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, max_c = 0, max_cc = 0;
    string c, cc;
    map <string, int> v_country, v_chef;
    map <string, string> chef;

    cin >> n >> m;

    while (n--) {
        cin >> c >> cc;

        chef[c] = cc;
    }

    while (m--) {
        cin >> c;

        v_chef[c]++;
        v_country[chef[c]]++;
    }

    for (auto it : v_chef) {
        if (it.second > max_c) {
            max_c = it.second;
        }
    }

    for (auto it : v_country) {
        if (it.second > max_cc) {
            max_cc = it.second;
        }
    }

    c = cc = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

    for (auto it : v_chef) {
        if (it.second == max_c) {
            c = min(c, it.first);
        }
    }

    for (auto it : v_country) {
        if (it.second == max_cc) {
            cc = min(cc, it.first);
        }
    }

    cout << cc << "\n" << c << "\n";

    return 0;
}