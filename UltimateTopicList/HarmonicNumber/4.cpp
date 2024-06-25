#include <bits/stdc++.h>

using namespace std;

int N = 1e6 + 5;
vector <int> divisor_count;

void fill_divisor_count()
{
    int i, j;

    divisor_count.resize(N, 0);

    for (i = 1; i < N; i++) {
        for (j = i; j < N; j += i) {
            divisor_count[j]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_divisor_count();

    int t, a, b;

    cin >> t;

    while (t--) {
        cin >> a >> b;

        cout << divisor_count[__gcd(a, b)] << "\n";
    }

    return 0;
}