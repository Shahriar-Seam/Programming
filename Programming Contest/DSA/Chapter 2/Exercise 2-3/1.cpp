#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0, n, i;
    char s[10], t[10];

    cin >> n;

    for (i = 1; ; i++) {
        itoa(i, s, 10);

        strcpy(t, s);

        strrev(t);

        if (strcmp(s, t) == 0) {
            cnt++;
        }

        if (cnt == n) {
            cout << s;
            break;
        }
    }

    return 0;
}