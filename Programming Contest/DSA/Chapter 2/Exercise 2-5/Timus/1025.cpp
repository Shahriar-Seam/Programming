#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, i, temp, cnt = 0;
    vector <int> v;

    cin >> k;

    for (i = 0; i < k; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (i = 0; i <= k / 2; i++) {
        cnt += ceil(v.at(i) / 2.0);
    }
    
    cout << cnt;

    return 0;
}