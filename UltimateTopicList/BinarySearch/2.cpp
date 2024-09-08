#include <bits/stdc++.h>

using namespace std;

int bin_search(vector <int> &v, int key)
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, key;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    while (k--) {
        cin >> key;

        cout << bin_search(v, key) << "\n";
    }

    return 0;
}