#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string t, c;
    pair <string, string> p;
    set <pair <string, string> > s;

    cin >> n;

    while (n--) {
        cin >> t >> c;

        p = {t, c};

        s.insert(p);
    }

    cout << s.size();

    return 0;
}