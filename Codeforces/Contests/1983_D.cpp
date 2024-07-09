#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp, sum = 0;
    map <int, int> a, b, dist;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        a[temp] = i;
    }

    for (i = 0; i < n; i++) {
        cin >> temp;

        b[temp] = i;
    }

    map <int, int> :: iterator it1 = begin(a);
    map <int, int> :: iterator it2 = begin(b);
    
    while (it1 != end(a)) {
        dist[abs(it1->second - it2->second)]++;

        it1++;
        it2++;
    }

    for (auto it : dist) {
        sum += it.second;
    }

    puts(sum & 1 ? "NO" : "YES");
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