#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, d;

double b[maxn], p[maxn], mp[maxn];
int a[maxn];
int Binary_Search(double a[], double value)
{
    int l = 0, r = n - 1;
    int result = -5;
    int i = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // cout<<"lr "<<l<<" "<<r<<endl;
        if (a[mid] == value)
        {
            result = mid;
            r = mid - 1;
        }

        else if (a[mid] < value)
        {

            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        i++;
    }

    return result;
}
bool cheak(double x, int &s, int &e)
{
    int i;
    for (i = 0; i < n; i++)
    {
        b[i] = a[i] - x;
    }
    p[0] = b[0];
    for (i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + b[i];
    }
    mp[0] = p[0];
    for (i = 1; i < n; i++)
    {
        mp[i] = min(mp[i - 1], p[i]);
    }

    for (i = n - 1; i + 1 - d >= 0; i--)
    {
        if (p[i] >= 0)
        {
            s = 1;
            e = i+1;

            return true;
        }
        if (i - d >= 0 && p[i] >= mp[i - d])
        {
            s = Binary_Search(mp, mp[i - d])+2;
            e = i+1;

            return true;
        }
    }

    return false;
}
int main()
{
    int i;
    cin >> n >> d;
    for (i = 0; i < n; i++)
        cin >> a[i];
    double l = 0, r = 100;
    int s = 0, e = 0;
    i = 0;

    while (i < 100)
    {
        double m = (l + r) / 2;

        if (cheak(m, s, e))
        {

            l = m;
        }
        else
            r = m;
        i++;
    }

    cout << s  << " " << e  << endl;
}

//2nd