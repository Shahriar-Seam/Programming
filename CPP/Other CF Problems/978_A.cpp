#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, *arr, i, s;
    vector <int> v;

    cin >> n;

    arr = new int[n];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = n - 1; i >= 0; i--) {
        if (find(v.begin(), v.end(), arr[i]) == v.end()) {
            v.push_back(arr[i]);
        }
    }

    s = v.size();

    cout << s << "\n";

    for (i = s - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }

    delete[] arr;

    return 0;
}