#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int i, len;

    cin >> s;

    len = s.length();

    for (i = 0; i < len; i++) {
        if (s[i] == ',') {
            s[i] = ' ';
        }
        else {
            s[i] = s[i] ^ 32;
        }
    }

    cout << s;

    return 0;
}