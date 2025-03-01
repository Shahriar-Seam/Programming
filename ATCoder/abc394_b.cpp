#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <pair <int, string> > v(n);

    for (auto &it : v) {
        cin >> it.second;

        it.first = it.second.size();
    }
    
    sort(v.begin(), v.end());

    for (auto it : v) {
        cout << it.second;
    }

    return 0;
}