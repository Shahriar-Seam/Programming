#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp, i;
    multiset <int> towers;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        auto it = towers.upper_bound(temp);

        if (it == towers.end()) {
            towers.insert(temp);
        }
        else {
            towers.erase(it);
            towers.insert(temp);
        }
    }

    cout << towers.size();

    return 0;
}