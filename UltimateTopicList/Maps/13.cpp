#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, box = 0;
    map <int, int> mp;

    cin >> n;

    while (n--) {
        cin >> a;

        mp[a]++;

        box = max(box, mp[a]);
    }

    cout << box;

    return 0;
}