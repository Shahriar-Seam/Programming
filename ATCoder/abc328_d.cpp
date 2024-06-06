#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    while (s.find("ABC") != s.npos) {
        s.erase(s.find("ABC"), 3);
    }

    cout << s;

    return 0;
}