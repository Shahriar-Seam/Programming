#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, w, mi, ma;

    cin >> a >> b >> w;

    w *= 1000;

    mi = ceil(w * 1.0 / b);
    ma = w / a;

    if (mi <= ma) {
        cout << mi << " " << ma << "\n";
    }
    else {
        cout << "UNSATISFIABLE\n";
    }

    return 0;
}