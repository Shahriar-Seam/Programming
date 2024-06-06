#include <bits/stdc++.h>

using namespace std;

int main()
{
    string src = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
    int t = 0;
    
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        if (src.find(str) != src.npos) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
