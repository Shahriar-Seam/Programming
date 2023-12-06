#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, qq, i;
    string temp;
    vector <string> s1;
    vector <string> s2;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> temp;

        s1.push_back(temp);
    }
    for (i = 0; i < m; i++) {
        cin >> temp;

        s2.push_back(temp);
    }

    cin >> qq;

    while (qq--) {
        cin >> q;

        cout << s1[(q - 1) % n] << s2[(q - 1) % m] << "\n";
    }

    return 0;
}