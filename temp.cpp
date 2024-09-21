#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> v(5, 0);

    for (int i = 0; i < 5; i++) {
        v[i] = i * i;
    }

    vector <int> a = v;

    for (auto it : a) {
        cout << it << " ";
    }

    return 0;
}