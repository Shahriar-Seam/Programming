#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, len;
    string s;

    cin >> t;

    while (t--) {
        cin >> s;

        len = s.size();

        if (s.substr(len - 2, 2) == "po") {
            cout << "FILIPINO\n";
        }
        else if ((s.substr(len - 4, 4) == "desu") || (s.substr(len - 4, 4) == "masu")) {
            cout << "JAPANESE\n";
        }
        else {
            cout << "KOREAN\n";
        }
    }

    return 0;
}