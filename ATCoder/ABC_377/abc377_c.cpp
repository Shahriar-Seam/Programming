#include <bits/stdc++.h>

using namespace std;

int inside(int a, int b, int n)
{
    return a > 0 && a <= n && b > 0 && b <= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    int i, j;
    set <pair <int, int> > s;

    cin >> n >> m;

    while (m--) {
        cin >> i >> j;

        s.insert({i, j});

        if (inside(i+2,j+1, n)) {
            s.insert({i+2,j+1});
        }
        if (inside(i+1,j+2, n)) {
            s.insert({i+1,j+2});
        }
        if (inside(i-1,j+2, n)) {
            s.insert({i-1,j+2});
        }
        if (inside(i-2,j+1, n)) {
            s.insert({i-2,j+1});
        }
        if (inside(i-2,j-1, n)) {
            s.insert({i-2,j-1});
        }
        if (inside(i-1,j-2, n)) {
            s.insert({i-1,j-2});
        }
        if (inside(i+1,j-2, n)) {
            s.insert({i+1,j-2});
        }
        if (inside(i+2,j-1, n)) {
            s.insert({i+2,j-1});
        }
    }

    cout << n * n - s.size();

    return 0;
}