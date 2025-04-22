#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, k, count = 0, i;
    int l = -1, r = -1;
    ordered_set osl, osr, osm;
    int fl = 0, fm = 0, fr = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    // left
    for (i = 0; i < n; i++) {
        if (!fl) {
            osl.insert({v[i], i});

            if ((*osl.find_by_order((osl.size() + 1) / 2 - 1)).first <= k) {
                fl = 1;
                l = i;
            }
        }
        else {
            if (v[i] > k) {
                osl.insert({v[i], i});

                if ((*osl.find_by_order((osl.size() + 1) / 2 - 1)).first <= k) {
                    l = i;
                }
                else {
                    break;
                }
            }
            else {
                cout << "YES\n";

                return;
            }
        }
    }

    if (fl) {
        osm.clear();
        for (i = l + 1; i < n - 1; i++) {
            osm.insert({v[i], i});

            if ((*osm.find_by_order((osm.size() + 1) / 2 - 1)).first <= k) {
                fm = 1;
                r = i;

                cout << "YES\n";

                return;
            }
        }

        osr.clear();
        for (i = n - 1; i > l + 1; i--) {
            osr.insert({v[i], i});

            if ((*osr.find_by_order((osr.size() + 1) / 2 - 1)).first <= k) {
                fr = 1;
                r = i;

                cout << "YES\n";

                return;
            }
        }
    }
    else {
        osr.clear();
        for (i = n - 1; i >= 0; i--) {
            if (!fr) {
                osr.insert({v[i], i});
    
                if ((*osr.find_by_order((osr.size() + 1) / 2 - 1)).first <= k) {
                    fr = 1;
                    r = i;
                }
            }
            else {
                if (v[i] > k) {
                    osr.insert({v[i], i});
    
                    if ((*osr.find_by_order((osr.size() + 1) / 2 - 1)).first <= k) {
                        r = i;
                    }
                    else {
                        break;
                    }
                }
                else {
                    cout << "YES\n";
    
                    return;
                }
            }
        }

        if (fr) {
            osm.clear();
            for (i = r - 1; i > 0; i--) {
                osm.insert({v[i], i});
    
                if ((*osm.find_by_order((osm.size() + 1) / 2 - 1)).first <= k) {
                    fm = 1;
                    r = i;
    
                    cout << "YES\n";
    
                    return;
                }
            }
    
            osl.clear();
            for (i = 0; i < r - 1; i++) {
                osl.insert({v[i], i});
    
                if ((*osl.find_by_order((osl.size() + 1) / 2 - 1)).first <= k) {
                    fl = 1;
                    l = i;
    
                    cout << "YES\n";
    
                    return;
                }
            }
        }
    }

    // right
    osl.clear();
    osm.clear();
    osr.clear();
    fl = fm = fr = 0;
    l = r = -1;

    for (i = n - 1; i >= 0; i--) {
        if (!fr) {
            osr.insert({v[i], i});

            if ((*osr.find_by_order((osr.size() + 1) / 2 - 1)).first <= k) {
                fr = 1;
                r = i;
            }
        }
        else {
            if (v[i] > k) {
                osr.insert({v[i], i});

                if ((*osr.find_by_order((osr.size() + 1) / 2 - 1)).first <= k) {
                    r = i;
                }
                else {
                    break;
                }
            }
            else {
                cout << "YES\n";

                return;
            }
        }
    }

    if (fr) {
        osm.clear();
        for (i = r - 1; i > 0; i--) {
            osm.insert({v[i], i});

            if ((*osm.find_by_order((osm.size() + 1) / 2 - 1)).first <= k) {
                fm = 1;
                l = i;

                cout << "YES\n";

                return;
            }
        }

        osl.clear();
        for (i = 0; i < r - 1; i++) {
            osl.insert({v[i], i});

            if ((*osl.find_by_order((osl.size() + 1) / 2 - 1)).first <= k) {
                fl = 1;
                l = i;

                cout << "YES\n";

                return;
            }
        }
    }
    else {
        osl.clear();
        for (i = 0; i < n; i++) {
            if (!fl) {
                osl.insert({v[i], i});
    
                if ((*osl.find_by_order((osl.size() + 1) / 2 - 1)).first <= k) {
                    fl = 1;
                    l = i;
                }
            }
            else {
                if (v[i] > k) {
                    osl.insert({v[i], i});
    
                    if ((*osl.find_by_order((osl.size() + 1) / 2 - 1)).first <= k) {
                        l = i;
                    }
                    else {
                        break;
                    }
                }
                else {
                    cout << "YES\n";
    
                    return;
                }
            }
        }

        if (fl) {
            osm.clear();
            for (i = l + 1; i < n - 1; i++) {
                osm.insert({v[i], i});
    
                if ((*osm.find_by_order((osm.size() + 1) / 2 - 1)).first <= k) {
                    fm = 1;
                    r = i;
    
                    cout << "YES\n";
    
                    return;
                }
            }
    
            osr.clear();
            for (i = n - 1; i > l + 1; i--) {
                osr.insert({v[i], i});
    
                if ((*osr.find_by_order((osr.size() + 1) / 2 - 1)).first <= k) {
                    fr = 1;
                    r = i;
    
                    cout << "YES\n";
    
                    return;
                }
            }
        }
    }

    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}