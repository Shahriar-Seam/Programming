#include <stdio.h>

#define sloth puts("SLOTH")
#define dragon puts("DRAGON")
#define tie puts("TIE")

void solve()
{
    int dsa1, toc1, dm1, total1;
    int dsa2, toc2, dm2, total2;

    scanf("%d %d %d", &dsa1, &toc1, &dm1);
    scanf("%d %d %d", &dsa2, &toc2, &dm2);

    total1 = dsa1 + toc1 + dm1;
    total2 = dsa2 + toc2 + dm2;

    if (total1 > total2) {
        dragon;
    }
    else if (total2 > total1) {
        sloth;
    }
    else {
        if (dsa1 > dsa2) {
            dragon;
        }
        else if (dsa1 < dsa2) {
            sloth;
        }
        else {
            if (toc1 > toc2) {
                dragon;
            }
            else if (toc1 < toc2) {
                sloth;
            }
            else {
                tie;
            }
        }
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}