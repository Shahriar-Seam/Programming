#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k, temp, i;
    set <int> s1, s2;
    int s1_size, s2_size;
    
    cin >> n >> m >> k;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (temp <= k) {
            s1.insert(temp);
        }
    }

    for (i = 0; i < m; i++) {
        cin >> temp;

        if (temp <= k) {
            s2.insert(temp);
        }
    }

    s1_size = s1.size();
    s2_size = s2.size();

    vector <int> v(s1_size + s2_size);

    auto it = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());

    v.resize(it - v.begin());

    if (v.size() < k) {
        puts("NO");

        return;
    }
    else if ((s1_size < (k / 2)) || (s2_size < (k / 2))) {
        puts("NO");

        return;
    }
    else {
        puts("YES");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}