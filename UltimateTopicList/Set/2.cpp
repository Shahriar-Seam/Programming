#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set <int> s;
    int n, x;

    cin >> n;

    while (n--) {
        cin >> x;

        s.insert(x);
    }

    cout << s.size();

    return 0;
}