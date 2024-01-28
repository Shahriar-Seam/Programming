#include <stdio.h>

#define yes puts("YES")
#define no puts("NO")
#define ll long long int

ll max(ll a, ll b)
{
    return (a > b ? a : b);
}

ll min(ll a, ll b)
{
    return (a < b ? a : b);
}

int main()
{
    ll t, r, b, d;

    scanf("%lld", &t);

    while (t--) {
        scanf("%lld %lld %lld", &r, &b, &d);

        if (max(r, b) > min(r, b) * (d + 1)) {
            no;
        }
        else {
            yes;
        }
    }

    return 0;
}