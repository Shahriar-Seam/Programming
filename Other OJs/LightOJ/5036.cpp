#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, w, sum, max_sum = 0, max_i = 0;
    int arr[128], i, j;
    char ch;
    string *s;

    for (i = 0; i < 128; i++) {
        arr[i] = 1;
    }

    cin >> n >> m;

    s = new string[n]();

    while (m--) {
        cin >> ch >> w;
        arr[ch] = w;
    }

    for (i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (i = 0; i < n; i++) {
        sum = 0;

        for (j = 0; j < s[i].size(); j++) {
            sum += arr[s[i][j]];
        }

        if (max_sum < sum) {
            max_sum = sum;
            max_i = i;
        }
    }

    cout << s[max_i] << " " << max_sum << endl;

    return 0;
}
