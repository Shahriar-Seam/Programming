#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, j;
    int x1, y1, z1, x2, y2, z2, xCommon, yCommon, zCommon;
    int xFar, yFar, zFar, xNear, yNear, zNear;

    cin >> t;

    for (i = 1; i <= t; i++) {
        xFar = 0, yFar = 0, zFar = 0;
        xNear = 1001, yNear = 1001, zNear = 1001;
        
        cin >> n;

        for (j = 1; j <= n; j++) {
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

            xFar = max({x1, xFar});
            yFar = max({y1, yFar});
            zFar = max({z1, zFar});

            xNear = min({x2, xNear});
            yNear = min({y2, yNear});
            zNear = min({z2, zNear});
        }

        xCommon = (xNear - xFar);
        yCommon = (yNear - yFar);
        zCommon = (zNear - zFar);

        if (xCommon > 0 && yCommon > 0 && zCommon > 0) {
            printf("Case %d: %d\n", i, xCommon * yCommon * zCommon);
        }
        else {
            printf("Case %d: 0\n", i);
        }
    }
    return 0;
}