#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, n, m, temp, temp2;
    set <int> cnt;

    cin >> n >> m;

    while (n--) {
        cin >> temp;

        for (i = 0; i < temp; i++) {
            cin >> temp2;
            cnt.insert(temp2);
        }
    }

    cnt.size() == m ? cout << "YES\n" : cout << "NO\n";

    return 0;
}