#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    vector <vector <long long> > v(0, vector <long long> (3));

    vector <long long> arr(n);

    for (auto &it : arr) {
        cin >> it;
    }

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            long long a, b, u;

            cin >> a >> b >> u;

            v.push_back({a, b, u});
        }
        else {
            long long k;
            
            cin >> k;
            
            long long num = arr[k - 1];

            for (auto it : v) {
                if (it[0] <= k && k <= it[1]) {
                    num += it[2];
                }
            }

            cout << num << "\n";
        }
    }
    
    return 0;
}