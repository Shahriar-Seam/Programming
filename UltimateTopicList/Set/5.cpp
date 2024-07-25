#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp, rounds = 0, i, prev;
    set <int> s;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (temp == 1) {
            s.insert(temp);

            rounds++;

            continue;
        }

        auto it = s.lower_bound(temp);

        if (it == s.begin() || *--it != temp - 1) {
            rounds++;
        }

        s.insert(temp);
    }

    cout << rounds;

    return 0;
}