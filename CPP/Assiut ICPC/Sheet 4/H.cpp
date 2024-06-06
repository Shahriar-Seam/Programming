#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;

    cin >> t;

    while (t--) {
        cin >> s;

        if ((s.find("101") != string::npos) || (s.find("010") != string::npos)) {
            cout << "Good\n";
        }
        else {
            cout << "Bad\n";
        }
    }

    return 0;
}