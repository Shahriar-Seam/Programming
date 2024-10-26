#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    vector <string> s(8);
    set <int> cols, rows;

    for (auto &it : s) {
        cin >> it;
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (s[i][j] == '#') {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    cout << (8 - rows.size()) * (8 - cols.size()) << "\n";

    return 0;
}