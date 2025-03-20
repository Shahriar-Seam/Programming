#include <bits/stdc++.h>

using namespace std;

void solve(double p, double q, double r, double s)
{
    double pq = p - q, rs = r - s;
    double result = 1.0;

    while (p + q + r + s + pq + rs > 0) {
        if (result > 1e12) {
            if (r) {
                result /= r;
    
                r--;
            }

            if (q) {
                result /= q;
    
                q--;
            }

            if (pq) {
                result /= pq;
    
                pq--;
            }
        }
        if (result < 1) {
            if (p) {
                result *= p;

                p--;
            }

            if (s) {
                result *= s;

                s--;
            }

            if (rs) {
                result *= rs;

                rs--;
            }
        }

        if (p) {
            result *= p;

            p--;
        }

        if (r) {
            result /= r;

            r--;
        }

        if (s) {
            result *= s;

            s--;
        }

        if (q) {
            result /= q;

            q--;
        }

        if (rs) {
            result *= rs;

            rs--;
        }

        if (pq) {
            result /= pq;

            pq--;
        }
    }

    cout << result << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(5);

    int p, q, r, s;

    while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
        solve(p, q, r, s);
    }

    return 0;
}