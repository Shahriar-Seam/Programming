#include <bits/stdc++.h>

using namespace std;

bool is_set(int n, int i)
{
    return n & (1 << i);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;
    int a, b, c;
    int ab, bc, ca, a_b, b_c, c_a;
    vector <int> v;

    cin >> n >> k;

    cout << "and 1 2" << endl;
    cin >> ab;

    cout << "or 1 2" << endl;
    cin >> a_b;

    cout << "and 2 3" << endl;
    cin >> bc;

    cout << "or 2 3" << endl;
    cin >> b_c;

    cout << "and 3 1" << endl;
    cin >> ca;

    cout << "or 3 1" << endl;
    cin >> c_a;

    a = (ab | ca);
    b = (ab | bc);
    c = (bc | ca);

    for (i = 0; i < 31; i++) {
        if (is_set(ab, i) || is_set(bc, i) || is_set(ca, i)) {
            continue;
        }
        
        if (!is_set(a_b, i) && is_set(b_c, i) && is_set(c_a, i)) {
            c |= (1 << i);
        }
        else if (is_set(a_b, i) && !is_set(b_c, i) && is_set(c_a, i)) {
            a |= (1 << i);
        }
        else if (is_set(a_b, i) && is_set(b_c, i) && !is_set(c_a, i)) {
            b |= (1 << i);
        }
    }

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    while (v.size() < n) {
        cout << "and 1 " << v.size() + 1 << endl;
        cin >> ab;

        cout << "or 1 " << v.size() + 1 << endl;
        cin >> a_b;

        b = ab;

        for (i = 0; i < 31; i++) {
            if (!is_set(a, i) && is_set(a_b, i)) {
                b |= (1 << i);
            }
        }

        v.push_back(b);
    }

    sort(v.begin(), v.end());

    cout << "finish " << v[k - 1] << endl;
    
    return 0;
}