#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string str;

    cin >> t;

    while (t--) {
        cin >> str;

        if (str.length() <= 10) {
            cout << str << "\n";
            continue;
        }
        
        cout << str[0] << str.length() - 2 << str[str.length() - 1] << "\n";
    }

    return 0;
}