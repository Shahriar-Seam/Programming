#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    string s, s2;

    cin >> n;
    cin >> s;

    for (i = 0; i < n; i++) {
        if (s[i] == '1' || s[i] == '0') {
            continue;
        }
        else if (s[i] == '4') {
            s2 += "322";
        }
        else if (s[i] == '6') {
            s2 += "53";
        }
        else if (s[i] == '8') {
            s2 += "7222";
        }
        else if (s[i] == '9') {
            s2 += "7332";
        }
        else {
            s2 += s[i];
        }
    }

    sort(s2.begin(), s2.end());

    reverse(s2.begin(), s2.end());

    cout << s2;

    return 0;
}