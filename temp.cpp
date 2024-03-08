#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector <string> strs;
    int i = 0, j = 0, min_size = 1000, f;
    string s;
    char c;

    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");

    for (i = 0; i < strs.size(); i++) {
        min_size = min(min_size, (int) strs[i].size());
    }

    for (i = 0; i < min_size; i++) {
        c = strs[0][i];
        f = 1;

        cout << c << endl;

        for (j = 0; j < strs.size(); j++) {
            if (c != strs[j][i]) {
                f = 0;

                break;
            }
        }

        if (f == 1) {
            s.push_back(c);
        }
    }

    cout << s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}