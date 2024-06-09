#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {5, 6, 7, 8, 9};
    int i, j;
    set <int> s;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            s.insert((arr[i] + arr[j]) % 10);
        }
    }

    for (auto it : s) {
        cout << it << " ";
    }

    return 0;
}