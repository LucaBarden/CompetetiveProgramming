#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define CIN                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define mod 1000000007
#define db double
#define ft float
#define int long long
#define vi vector<int>
#define pi pair<int, int>
#define ppi pair<pi, int>
#define vvi vector<vi>
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define vs vector<string>
#define vpp vector<pi>
#define si stack<int>
#define ss stack<string>
#define sc stack<char>
#define pb push_back
#define print(i) cout << i << endl

const int N = 200 + 5;

unordered_map<string, int> mp;


struct node
{
  int v;
  double w;
};

vector<node> g[N];

bool ok;
bool vis[N];

double ans;
int st, en;
int cnt = 1;


void dfs(int st, int en, double now)
{
  if (ok)
    return;
  if (st == en)
  {
    ok = true;
    ans = now;
  }
  else
  {
    for (auto it : g[st])
    {
      int v = it.v;
      double w = it.w;

      if (vis[v])
        continue;
      else
        vis[v] = 1;

      if (v != en)
      {
        dfs(v, en, now * w);
      }
      else
      {
        ok = true;
        ans = now * w;
      }
    }
  }
}

signed main()
{
  CIN;
  int n, m;
  cin >> n >> m;
  while (n--)
  {
    char eq;
    double u, v;
    string x, y;
    cin >> u >> x >> eq >> v >> y;

    if (!mp[x])
      mp[x] = ++cnt;
    if (!mp[y])
      mp[y] = ++cnt;

    g[mp[x]].push_back({mp[y], v});
    g[mp[y]].push_back({mp[x], (u / v)});
  }

  for (int z = 0; z < m; z++)
  {
    memset(vis, 0, sizeof vis);

    string to;
    string st_s, en_s;
    double x;

    cin >> x >> st_s >> to >> en_s;

    ok = false;
    ans = 0;
    st = mp[st_s];
    en = mp[en_s];
    vis[st] = 1;
    dfs(st, en, x);
    if (ok)
      printf("%e\n", ans);
    else
      printf("impossible\n");
  }
}
