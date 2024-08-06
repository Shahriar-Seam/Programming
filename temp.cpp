#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    vector <int> v;
    queue <int> q;

    for (i = 0; i < 5; i++) {
        v.push_back(i);
    }

    sort(v.begin(), v.end());

    for (auto it : v) {
        cout << it << " ";
    }

    return 0;
}