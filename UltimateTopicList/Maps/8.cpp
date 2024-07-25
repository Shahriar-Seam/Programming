#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, a, b;
    map <string, string> mp;

    while (getline(cin, s) && s != "\0") {
        stringstream ss(s);

        getline(ss, a, ' ');
        getline(ss, b, ' ');

        mp[b] = a;
    }

    while (getline(cin, s) && s != "\0") {
        if (mp[s] == "") {
            mp[s] = "eh";
        }

        cout << mp[s] << "\n";
    }

    return 0;
}