#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, n;

    cin >> s;

    n = s.size();

    for (i = 0; i >= 0 && i < n - 1; ) {
        if (s[i] == 'W' && s[i + 1] == 'A') {
            s[i] = 'A';
            s[i + 1] = 'C';
            
            if (i > 0) {
                i = i - 1;
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }

    cout << s << "\n";

    return 0;
}