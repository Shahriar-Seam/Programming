#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, power = 0, n = 0;

    cin >> s;

    for (i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'N') {
            n++;
        }
        else if (s[i] == 'S') {
            if (n > 0) {
                power++;
                n--;
            }
        }
    }

    cout << power << "\n";

    return 0;
}