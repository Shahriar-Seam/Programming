#include <bits/stdc++.h>

using namespace std;

int N = 1e6 + 5;
vector <int> number_of_divisors;

void fill_number_of_divisors()
{
    int i, j;

    number_of_divisors.resize(N, 0);

    for (i = 1; i < N; i++) {
        for (j = i; j < N; j += i) {
            number_of_divisors[j]++;
        }
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << number_of_divisors[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_number_of_divisors();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}