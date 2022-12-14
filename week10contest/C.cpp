#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 5; // oops!

int n, m, mn_back[MAXN], h[MAXN], par[MAXN], mx;
vi N[MAXN], N2[MAXN];
bitset<MAXN> mark;

int getpar(int v)
{
  return (par[v] == v ? v : par[v] = getpar(par[v]));
}

void merge(int v, int u)
{
  int p1 = getpar(v), p2 = getpar(u);
  par[p1] = p2;
}

void dfs(int v)
{
  mark[v] = 1;
  mn_back[v] = h[v];
  for (auto u : N[v])
  {
    if (!mark[u])
    {
      h[u] = h[v] + 1;
      dfs(u);
      if (mn_back[u] < h[v])
      {
        merge(u, v);
      }
      mn_back[v] = min(mn_back[v], mn_back[u]);
    }
    else if (h[v] > h[u] + 1)
    {
      merge(v, u);
      mn_back[v] = min(mn_back[v], h[u]);
    }
  }
}

void dfs_build(int v)
{
  mark[v] = 1;
  for (auto u : N[v])
  {
    if (!mark[u])
    {
      dfs_build(u);
      int p1 = getpar(v), p2 = getpar(u);
      mx = p1;
      N2[p1].pb(p2), N2[p2].pb(p1);
    }
  }
}

void dfs_dia(int v)
{
  mark[v] = 1;
  if (h[v] > h[mx])
    mx = v;
  for (int u : N2[v])
  {
    if (!mark[u])
    {
      h[u] = h[v] + 1;
      dfs_dia(u);
    }
  }
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin >> x >> y;
    N[x].pb(y), N[y].pb(x);
  }
  iota(par, par + n + 1, 0);
  dfs(1);

  mark.reset();
  dfs_build(1);

  mx = getpar(1);
  mark.reset();
  fill(h, h + n + 1, 0);
  dfs_dia(mx);

  mark.reset();
  fill(h, h + n + 1, 0);
  dfs_dia(mx);

    return 0;
}
