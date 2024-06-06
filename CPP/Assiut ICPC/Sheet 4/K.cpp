#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i;
    string s1, s2, s3;

    cin >> t;

    while (t--) {
        cin >> s1 >> s2;

        s3 = "";

        for (i = 0; i < min({s1.length(), s2.length()}); i++) {
            s3 += s1[i];
            s3 += s2[i];
        }

        if (s1.length() > s2.length()) {
            s3 += s1.substr(i);
        }
        else {
            s3 += s2.substr(i);
        }

        cout << s3 << "\n";
    }

    return 0;
}