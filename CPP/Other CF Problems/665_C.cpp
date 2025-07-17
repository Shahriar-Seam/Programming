#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i;

    cin >> s;

    for (i = 1; i < s.size() - 1; i++) {
        if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
            if (s[i] == 'z') {
                s[i] = 'a';
            }
            else {
                s[i]++;
            }
        }
    }

    if (s[0] == s[1]) {
        if (s[0] == 'z') {
            s[0] = 'a';
        }
        else {
            s[0]++;
        }
    }

    for (i = 2; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            if (s[i - 1] == 'z') {
                s[i - 1] = 'a';
            }
            else {
                s[i - 1]++;
            }

            if (s[i - 1] == s[i - 2]) {
                if (s[i - 1] == 'z') {
                    s[i - 1] = 'a';
                }
                else {
                    s[i - 1]++;
                }
            }
        }
    }

    cout << s << "\n";

    return 0;
}