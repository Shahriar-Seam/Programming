#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, f = 1;
    string s = "", c;

    cin >> n;

    while (n--) {
        cin >> c >> l;

        if (s.length() > 100) {
            f = 0;

            break;
        }

        if (l < 102) {
            while (l--) {
                s += c;
            }
        }
        else {
            f = 0;

            break;
        }
    }

    if (f && s.size() <= 100) {
        cout << s << "\n";
    }
    else {
        cout << "Too Long\n";
    }

    return 0;
}