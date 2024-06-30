#include <bits/stdc++.h>

using namespace std;

int f;

void is_possible(long long n, long long N)
{
    if (n > N) {
        return;
    }
    if (n == N) {
        f = 1;

        return;
    }

    is_possible(n * 10, N);
    is_possible(n * 20, N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        f = 0;

        is_possible(1, n);

        cout << (f ? "YES\n" : "NO\n");
    }

    return 0;
}

// doesn't work