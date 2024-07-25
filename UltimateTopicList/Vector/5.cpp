#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp, count = 0;
    map <int, int> mp;

    cin >> n;

    while (n--) {
        cin >> temp;

        mp[temp]++;
    }

    for (auto it : mp) {
        if (it.second < it.first) {
            count += it.second;
        }
        else {
            count += it.second - it.first;
        }
    }

    cout << count;

    return 0;
}