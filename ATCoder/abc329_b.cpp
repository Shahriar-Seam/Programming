#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set <int> arr;
    int i, n, num;

    cin >> n;

    while (n--) {
        cin >> num;

        arr.insert(num);
    }

    auto it = arr.end();

    it--;
    it--;

    cout << *it;

    return 0;
}