#include <bits/stdc++.h>

using namespace std;

int get_random(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution <> dis(a, b);

    return dis(gen);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> v = {9071685, 9199496, 9206925, 9339704, 9363584, 9437056, 9478910, 9491625, 9498555, 9592504, 9627915, 9660950, 9773505, 9892936, 10000000, 9827278, 9182014, 9869847, 9206169, 9171762, 9382892, 9405335, 9553293, 9506132, 9856143};

    int t = 100000 - 213;

    // cout << t << "\n";

    while (t--) {
        cout << v[get_random(0, 100) % v.size()] << "\n";
    }

    return 0;
}