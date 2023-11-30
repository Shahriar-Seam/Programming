#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        string s, str;

        cin >> s;

        str = s;

        reverse(s.begin(), s.end());

        str += s;

        cout << str << "\n";
    }

    return 0;
}