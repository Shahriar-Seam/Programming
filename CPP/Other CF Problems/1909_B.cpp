#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    long long temp, j, m;
    vector <long long> arr;
    set <long long> s;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        arr.push_back(temp);

        s.insert(temp % 2);
    }

    if (s.size() == 2) {
        cout << "2\n";
    }
    else {
        j = *min_element(arr.begin(), arr.end());
        m = *max_element(arr.begin(), arr.end());

        while (s.size() != 2 && j <= m) {
            s.clear();
            j++;

            for (i = 0; i < n; i++) {
                s.insert(arr[i] % j);
            }
        }

        cout << j << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}