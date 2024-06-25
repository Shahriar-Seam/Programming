#include <bits/stdc++.h>

using namespace std;

int N = 5e5 + 5;
vector <int> div_sum;

void fill_div_sum()
{
    int i, j;

    div_sum.resize(N);

    for (i = 0; i < N; i++) {
        div_sum[i] = -i;
    }

    for (i = 1; i < N; i++) {
        for (j = i; j < N; j += i) {
            div_sum[j] += i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_div_sum();

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        cout << div_sum[n] << "\n";
    }

    return 0;
}