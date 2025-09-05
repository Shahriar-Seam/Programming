#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// #define int long long
#define endl '\n'
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define maxsize 200005
#define M 998244353
#define mod 998244353
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

bitset <maxsize + 1> marked;
vector<int> primes;
int sign[maxsize + 1];

int cntz[maxsize + 1];

int signa[maxsize + 1];

int cntza[maxsize + 1];

map<int, map<int, int>> primefactor;
map<int, map<int, int>> pf;
void sieve() {
  int i, j;
  marked[0] = marked[1] = 1;
  for (i = 3; i * i <= maxsize; i += 2) {
    if (!marked[i]) {
      for (j = i * i; j <= maxsize; j += 2 * i) {
        marked[j] = 1;
      }
    }
  }
  primes.push_back(2);
  for (i = 3; i <= maxsize; i += 2) {
    if (marked[i] == false)
      primes.push_back(i);
  }
}

const int N = 3e5 + 9, LG = 20;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];

void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++)
    par[u][i] = par[par[u][i - 1]][i - 1];

  for (auto v : g[u])
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
}

int lca(int u, int v) {
  if (dep[u] < dep[v])
    swap(u, v);
  for (int k = LG; k >= 0; k--) {
    if (dep[par[u][k]] >= dep[v])
      u = par[u][k];
  }
  if (u == v)
    return u;
  for (int k = LG; k >= 0; k--) {
    if (par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}

void factorize(int ind, int n) {
  if (n == 0 || n == 1)
    return;
  int i = 0;
  for (i = 0; i < primes.size() && primes[i] <= 500 && primes[i] <= n; i++) {
    while (n % primes[i] == 0) {
      pf[ind][primes[i]]++;
      n /= primes[i];
    }
  }
  if (n > 1) {
    pf[ind][n]++;
  }
}

typedef unsigned long long ull;
typedef long long ll;

ull modmul(ull a, ull b, ull m)
{
    ll ret = a * b - m * ull(1.L / m * a * b);

    return ret + m * (ret < 0) - m * (ret >= (ll) m);
}

ull modpow(ull b, ull e, ull m)
{
    ull ans = 1;

    for (; e; b = modmul(b, b, m), e /= 2) {
        if (e & 1) {
            ans = modmul(ans, b, m);
        }
    }

    return ans;
}

// Miller Rabin
bool isPrime(ull n)
{
    if (n < 2 || n % 6 % 4 != 1) {
        return (n | 1) == 3;
    }

    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n - 1);
    ull d = n >> s;

    for (ull a : A) {
        ull p = modpow(a % n, d, n);
        ull i = s;

        while (p != 1 && p != n - 1 && a % n && i--) {
            p = modmul(p, p, n);
        }

        if (p != n - 1 && i != s) {
            return 0;
        }
    }

    return 1;
}

ull pollard_rho(ull n) {
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;

    auto f = [&](ull x) {
        return modmul(x, x, n) + i;
    };

    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) {
            x = ++i;
            y = f(x);
        }
        if ((q = modmul(prd, max(x, y) - min(x, y), n))) {
            prd = q;
        }

        x = f(x), y = f(f(y));
    }

    return __gcd(prd, n);
}

vector <ull> factor(ull n) {
    if (n == 1) {
        return {};
    }
    if (isPrime(n)) {
        return {n};
    }

    ull x = pollard_rho(n);

    auto l = factor(x), r = factor(n / x);

    l.insert(l.end(), begin(r), end(r));

    return l;
}

void dfs2(int u, int parent, int *visited) {
  if (visited[u] == 1)
    return;
  visited[u] = 1;
  if (parent == 0) {
    for (auto it : pf[u]) {
      if (it.second % 2 == 1) {
        primefactor[u][it.first] = it.second;
      }
    }
    signa[u] = sign[u];
    cntza[u] = cntz[u];
  } else {
    signa[u] = signa[parent] + sign[u];
    cntza[u] = cntza[parent] + cntz[u];

    for (auto it : primefactor[parent]) {
      int s, v;
      s = it.first;
      v = it.second;
      if (pf[u].find(s) != pf[u].end()) {
        int cnt1 = pf[u][s] + v;
        if (cnt1 % 2 == 1) {
          primefactor[u][s] = cnt1;
        }
      } else {
        primefactor[u][s] = primefactor[parent][s];
      }
    }
    for (auto &it : pf[u]) {
      int s, v;
      s = it.first;
      v = it.second;
      if (primefactor[parent].find(s) == primefactor[parent].end()) {
        if (v % 2 == 1) {
          primefactor[u][s] = v;
        }
      }
    }
  }

//     cout << "dfs "<<u<<endl;
//       for (auto it : primefactor[u]) {
//         int ss = it.first;
//         int vv = it.second;
//         cout << ss << " " << vv << endl;
//       }

  for (auto &v : g[u]) {
    dfs2(v, u, visited);
  }
}
int32_t main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve();

  int n;
  cin >> n;
  int a[n + 1];

  int i;
  for (i = 1; i <= n; i++)

  {
    cin >> a[i];
    if (a[i] == 0)
      cntz[i] = 1;
    if (a[i] < 0) {
      sign[i] = 1;
      a[i] *= -1;
    } else
      sign[i] = 0;

    // factorize(i, a[i]);

    vector <ull> f = factor(a[i]);

    for (auto &it : f) {
        pf[i][it]++;
    }
  }

  for (i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1);

  int visited[n + 1] = {};
  dfs2(1, 0, visited);

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;

    int p = lca(u, v);

    map<int, int> mp1, mp2, mpf;
    int minus = 0, zero = 0;

    minus = signa[u] + signa[v] - 2 * signa[p] + sign[p];
    zero = cntza[u] + cntza[v] - 2 * cntza[p] + cntz[p];

    if (zero > 0)
      cout << "Yes\n";
    else if (minus % 2 == 1)
      cout << "No\n";
    else {
     //  cout << "u\n";
     //  for (auto it : primefactor[u]) {
     //    int ss = it.first;
     //    int vv = it.second;
     //    cout << ss << " " << vv << endl;
     //  }

     //  cout << "v\n";
     //  for (auto it : primefactor[v]) {
     //    int ss = it.first;
     //    int vv = it.second;
     //    cout << ss << " " << vv << endl;
     //  }

     //  cout << "p\n";
     //  for (auto it : primefactor[p]) {
     //    int ss = it.first;
     //    int vv = it.second;
     //    cout << ss << " " << vv << endl;
     //  }

     //   cout << "pfp\n";
     //  for (auto it : pf[p]) {
     //    int ss = it.first;
     //    int vv = it.second;
     //    cout << ss << " " << vv << endl;
     //  }
      for (auto &it : primefactor[u]) {
        int ss = it.first;
        int vv = it.second;

        if (primefactor[p].find(ss) == primefactor[p].end()) {
          mp1[ss] = vv;

        } else {
          mp1[ss] = vv + primefactor[p][ss];
        }
      }

      for (auto &it : primefactor[p]) {
        int ss = it.first;
        int vv = it.second;

        if (primefactor[u].find(ss) == primefactor[u].end()) {
          mp1[ss] = 1;
        }
      }

      for (auto &it : primefactor[v]) {
        int ss = it.first;
        int vv = it.second;

        if (primefactor[p].find(ss) == primefactor[p].end()) {
          mp2[ss] = vv;

        } else {
          mp2[ss] = vv + primefactor[p][ss];
        }
      }

      for (auto &it : primefactor[p]) {
        int ss = it.first;
        int vv = it.second;

        if (primefactor[v].find(ss) == primefactor[v].end()) {
          mp2[ss] = 1;
        }
      }

      for (auto &it : mp2)
        mp1[it.first] += it.second;
      for (auto &it : pf[p]) {
        mp1[it.first] += it.second;
      }

      int flag = 1;
      for (auto &it : mp1) {
        if (it.second % 2 == 1) {
          flag = 0;
          break;
        }
      }
      if (flag == 1)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }

  return 0;
}

/*

  Md. Siam Ahmed

  CSE, Khulna University

*/
