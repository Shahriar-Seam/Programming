#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int one, zero;

    cin >> s;

    one = count(s.begin(), s.end(), '1');
    zero = s.size() - one;

    if (one > zero) {
        cout << string(s.size(), '0') << "\n";
    }
    else if (one < zero) {
        cout << string(s.size(), '1') << "\n";
    }
    else {
        if (s[0] == '0') {
            cout << '1' + string(s.size() - 1, '0') << "\n";
        }
        else {
            cout << '0' + string(s.size() - 1, '1') << "\n";
        }
    }

    return 0;
}