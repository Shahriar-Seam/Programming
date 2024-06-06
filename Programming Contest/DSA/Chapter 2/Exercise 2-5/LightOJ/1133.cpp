#include <bits/stdc++.h>

using namespace std;

void addition(vector <int> &v, int k)
{
    int i;

    for (i = 0; i < v.size(); i++) {
        v[i] += k;
    }
}

void multiplication(vector <int> &v, int k)
{
    int i;

    for (i = 0; i < v.size(); i++) {
        v[i] *= k;
    }
}

void division(vector <int> &v, int k) {
    int i;

    for (i = 0; i < v.size(); i++) {
        v[i] /= k;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, _, i, n, m, temp, k;
    char ch;
    vector <int> v;

    cin >> t;

    for (_ = 1; _ <= t; _++) {
        cin >> n >> m;

        for (i = 0; i < n; i++) {
            cin >> temp;

            v.push_back(temp);
        }

        while (m--) {
            cin >> ch;

            if (ch == 'R') {
                reverse(v.begin(), v.end());
            }
            else if (ch == 'P') {
                int y, z;

                cin >> y >> z;

                swap(v[y], v[z]);
            }
            else if (ch == 'S') {
                cin >> k;

                addition(v, k);
            }
            else if (ch == 'M') {
                cin >> k;

                multiplication(v, k);
            }
            else {
                cin >> k;

                division(v, k);
            }
        }

        cout << "Case " << _ << ":" << "\n";
        
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << "\n";

        v.clear();
    }

    return 0;
}