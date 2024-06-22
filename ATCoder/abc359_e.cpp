#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m = 0, i;

    cin >> n;

    vector <int> h(n);
    vector <long long> a(n);

    for (auto &it : h) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (m < h[i]) {
            m = h[i];
            a[i] = m * (i + 1) + 1;
        }
        else {
            a[i] = a[i - 1] + h[i];
        }
    }

    for (auto it : a) {
        cout << it << " ";
    }

    return 0;
}