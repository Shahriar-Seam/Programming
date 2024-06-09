#include <bits/stdc++.h>

using namespace std;

void print_even_index(vector <int> &v, int index, int n)
{
    if (index < n) {
        print_even_index(v, index + 2, n);

        cout << v[index] << " ";
    }
    else {
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    print_even_index(v, 0, n);

    return 0;
}