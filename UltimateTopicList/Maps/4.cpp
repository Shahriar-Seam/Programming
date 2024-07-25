#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, value, i;
    string s;
    map <string, int> mp;

    cin >> m >> n;

    while (m--) {
        cin >> s >> value;

        mp[s] = value;
    }

    while (n--) {
        value = 0;
        
        while (1) {
            cin >> s;

            if (s == ".") {
                cout << value << "\n";

                break;
            }
            else {
                value += mp[s];
            }
        }
    }

    return 0;
}