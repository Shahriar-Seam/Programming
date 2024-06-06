#include <bits/stdc++.h>

using namespace std;

bool compare(pair <int, int> a, pair <int, int> b)
{
    if (a.second != b.second) {
        return a.second < b.second;
    }
    else {
        return a.first > b.first;
    }
}

void fill_vector(vector <pair <int, int> > &v)
{
    int i, j;

    for (i = 1; i <= 1000; i++) {
        v[i - 1].first = i;

        for (j = i; j <= 1000; j += i) {
            v[j - 1].second++;
        }
    }

    sort(v.begin(), v.end(), compare);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, n;
    vector <pair <int, int> > v(1000);

    fill_vector(v);

    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> n;

        cout << "Case " << i << ": " << v[n - 1].first << "\n";
    }

    return 0;
}