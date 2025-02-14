#include <bits/stdc++.h>

using namespace std;

void vacation(vector <vector <int> > &v, vector <vector <int> > &happy, int n)
{
    if (n == 0) {
        happy[n][0] = v[n][0];
        happy[n][1] = v[n][1];
        happy[n][2] = v[n][2];

        return;
    }

    vacation(v, happy, n - 1);

    happy[n][0] = v[n][0] + max(happy[n - 1][1], happy[n - 1][2]);
    happy[n][1] = v[n][1] + max(happy[n - 1][0], happy[n - 1][2]);
    happy[n][2] = v[n][2] + max(happy[n - 1][0], happy[n - 1][1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <vector <int> > v(n, vector <int> (3)), happy(n, vector <int> (3, 0));

    for (i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    vacation(v, happy, n - 1);

    cout << *max_element(happy[n - 1].begin(), happy[n - 1].end()) << "\n";

    return 0;
}