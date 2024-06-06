#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    if (((s.find("LLL") != string::npos)) || count(s.begin(), s.end(), 'A') > 1) {
        cout << "false";
    }
    else {
        cout << "true";
    }

    return 0;
}