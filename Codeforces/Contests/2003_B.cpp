#include <stdio.h>

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);
    
    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    cout << v[n / 2] << "\n";
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}