#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, x, y;
    string s;

    cin >> t;

    while (t--) {
        cin >> x >> y;
        cin >> s;

        if ((x >= 0 && y >= 0) && (x <= count(s.begin(), s.end(), 'R') && y <= count(s.begin(), s.end(), 'U'))) {
            cout << "YES\n";
        }
        else if ((x <= 0 && y >= 0) && (abs(x) <= count(s.begin(), s.end(), 'L') && y <= count(s.begin(), s.end(), 'U'))) {
            cout << "YES\n";
        }
        else if ((x >= 0 && y <= 0) && (x <= count(s.begin(), s.end(), 'R') && abs(y) <= count(s.begin(), s.end(), 'D'))) {
            cout << "YES\n";
        }
        else if ((x <= 0 && y <= 0) && (abs(x) <= count(s.begin(), s.end(), 'L') && abs(y) <= count(s.begin(), s.end(), 'D'))) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}