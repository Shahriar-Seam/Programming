#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;
    int it = -1, jt = -1;
    long long x, a, b, c;
    int X = 0;

    cin >> n >> k;
    cin >> x >> a >> b >> c;
    
    vector <pair <int, int> > in(k);
    vector <int> out(k);

    for (i = 0; i < k; i++) {
        it++;

        if (i > 0) {
            x = (a * x + b) % c;
            x = (x + c) % c;

            in[it] = {x, in[it - 1].second | x};
        }
        else {
            in[it] = {x, x};
        }
    }

    X = in[it].second;

    for (i = k; i < n; i++) {
        x = (a * x + b) % c;
        x = (x + c) % c;

        if (jt == -1) {
            while (it >= 0) {
                jt++;

                if (jt == 0) {
                    out[jt] = in[it].first;
                }
                else {
                    out[jt] = out[jt - 1] | in[it].first;
                }

                it--;
            }
        }

        if (it >= 0) {
            it++;

            in[it] = {x, in[it - 1].second | x};
        }
        else {
            it++;

            in[it] = {x, x};
        }

        jt--;

        if (jt >= 0) {
            X ^= out[jt] | in[it].second;
        }
        else {
            X ^= in[it].second;
        }
    }

    cout << X << "\n";

    return 0;
}