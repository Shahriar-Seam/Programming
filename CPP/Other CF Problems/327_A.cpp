#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, t, cnt = 0, ans = 0;
    vector <int> arr;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> t;

        arr.push_back(t);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cnt++;
        }
        if (arr[i] == 1) {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }

    cout << (n > 1 ? (ans + count(arr.begin(), arr.end(), 1)) : arr[0] == 1 ? 0 : 1);

    return 0;
}