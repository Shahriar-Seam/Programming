#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0;
    string s;

    cin >> n >> s;

    for (i = 1; i < n; i += 2) {
        if (s[i] == s[i - 1]) {
            if (s[i] == 'a') {
                s[i] = 'b';
            }
            else {
                s[i] = 'a';
            }

            count++;
        }
    }

    cout << count << "\n" << s << "\n";

    return 0;
}