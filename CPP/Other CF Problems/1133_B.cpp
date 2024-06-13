#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, temp, cnt = 0;
    int l, r;
    vector <int> v;

    cin >> n >> k;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (temp % k == 0) {
            cnt++;
        }
        else {
            v.push_back(temp % k);
        }
    }

    cnt /= 2;

    sort(v.begin(), v.end());

    for (l = 0, r = v.size() - 1; l < r ; ) {
        if (v[l] + v[r] > k) {
            r--;
        }
        else if (v[l] + v[r] < k) {
            l++;
        }
        else {
            cnt++;
            l++;
            r--;
        }
    } // two sum

    cout << cnt * 2 << "\n";

    return 0;
}