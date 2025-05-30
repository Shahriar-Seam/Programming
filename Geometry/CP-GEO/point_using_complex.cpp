#include <bits/stdc++.h>

using namespace std;

typedef double T;
typedef complex <T> pt;

#define x real()
#define y imag()

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pt p{2.0, 1.0};

    cout << abs(p) << " " << arg(p) << "\n";
    cout << polar(2.0, -M_PI / 4) << "\n";

    cout << (norm(p) == 5.0) << "\n";

    return 0;
}