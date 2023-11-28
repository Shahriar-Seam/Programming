#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, a, b, c, d, sum, thomas;
    vector <int> arr;

    cin >> n;

    t = n - 1;

    cin >> a >> b >> c >> d;

    thomas = a + b + c + d;

    arr.push_back(thomas);

    while (t--) {
        cin >> a >> b >> c >> d;

        sum = a + b + c + d;

        arr.push_back(sum);
    }

    sort(arr.begin(), arr.end(), greater <int> ());

    for (i = 0; i < n; i++) {
        if (arr[i] == thomas) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}