#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    map <string, int> mp;

    cin >> n;

    while (n--) {
        cin >> s;

        if (mp[s] == 0) {
            cout << "OK\n";
        }
        else {
            cout << s << mp[s] << "\n";
        }

        mp[s]++;
    }

    return 0;
}