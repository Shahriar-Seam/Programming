#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    map <int, int> mp;
    vector <int> v;

    while (scanf("%d", &n) != EOF) {
        mp[n]++;

        if (mp[n] == 1) {
            v.push_back(n);
        }
    }
    
    for (auto it : v) {
        cout << it << " " << mp[it] << "\n";
    }

    return 0;
}