#include <bits/stdc++.h>

using namespace std;

vector <int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool is_prime(int n)
{
    return binary_search(primes.begin(), primes.end(), n);
}

void recurse(int i, int n, vector <int> &circle, vector <bool> &used)
{
    if (i == n + 1) {
        if (is_prime(circle[n] + circle[1])) {
            for (int j = 1; j <= n; j++) {
                if (j > 1) {
                    cout << " ";
                }

                cout << circle[j];
            }

            cout << "\n";
        }

        return;
    }

    for (int j = 2; j <= n; j++) {
        if (!used[j]) {
            if (i == 1 || is_prime(circle[i - 1] + j)) {
                circle[i] = j;

                used[j] = true;

                recurse(i + 1, n, circle, used);

                used[j] = false;
            }
        }
    }
}

void solve(int32_t n)
{
    vector <int> circle(n + 1);
    vector <bool> used(n + 1, 0);

    circle[1] = 1;
    used[1] = true;

    recurse(2, n, circle, used);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t n, i = 1;

    while (cin >> n) {
        if (i > 1) {
            cout << "\n";
        }

        cout << "Case " << i++ << ":\n";

        solve(n);
    }

    return 0;
}