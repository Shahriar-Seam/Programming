#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int i, diff = 1000;

    cin >> s;

    for (i = 0; i < s.size() - 2; i++) {
        t = "";
        t += s[i];
        t += s[i + 1];
        t += s[i + 2];

        diff = min(diff, abs(753 - stoi(t)));
    }

    cout << diff;

    return 0;
}
