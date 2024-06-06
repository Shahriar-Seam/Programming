#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    int i;

    cin >> s1 >> s2;

    for (i = 0; i < s1.size(); ) {
        if (s2.find(s1[i]) != string::npos) {
            s1.erase(s1.begin() + i);
        }
        else {
            i++;
        }
    }

    cout << s1;

    return 0;
}