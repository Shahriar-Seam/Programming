#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int f = 0, i;

    cin >> s;

    if (count(begin(s), end(s), '0') > 0) {
        for (i = 0; i < s.size(); i++) {
            if (f == 0 && s[i] == '0') {
                f = 1;

                continue;
            }
            else {
                cout << s[i];
            }
        }
    }
    else {
        for (i = 1; i < s.size(); i++) {
            cout << s[i];
        }
    }

    return 0;
}