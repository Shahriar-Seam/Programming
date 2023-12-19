#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0, f;
    string s;

    while (getline(cin, s)) {
        f = 0;

        for (char c : s) {
            if (isalpha(c)) {
                f = 1;
                break;
            }
        }

        cnt += f;
    }

    cout << cnt;

    return 0;
}