#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    string *f;

    cin >> s;

    f = s.find("ABC");

    while (f != s.npos) {
        s.erase(f, 3);

        f = s.find("ABC");
    }

    cout << s;

    return 0;
}