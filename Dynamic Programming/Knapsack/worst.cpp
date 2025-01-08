#include <bits/stdc++.h>

using namespace std;

// O(2^n)
int knapsack(vector <int> &w, vector <int> &v, int n, int W)
{
    if (n == 0 || W == 0) {
        return 0;
    }

    if (w[n - 1] > W) {
        return knapsack(w, v, n - 1, W);
    }

    return max(knapsack(w, v, n - 1, W), v[n - 1] + knapsack(w, v, n - 1, W - w[n - 1]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W, i;

    cin >> n >> W;

    vector <int> w(n), v(n);

    for (i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    cout << knapsack(w, v, n, W) << "\n";

    return 0;
}