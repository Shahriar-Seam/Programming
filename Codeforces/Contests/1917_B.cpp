#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i;
    string s1, s2;
    set <string> str;

    cin >> t;

    while (t--) {
        cin >> n >> s1;

        reverse(s1.begin(), s1.end());

        s2 = s1;

        for (i = n - 1; i > 0; i--) {
            str.insert(s1.pop_back());
        }
    }

    return 0;
}