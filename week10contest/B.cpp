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

const int N = 4e5 + 5;
int tc, n, casee = 1, a[N], tin[N], low[N], timer;
int vis[N];

vector<int> x[N];
map<pair<int, int>, int> bridge, edgeNum;

void dfs(int v, int p = -1)
{
  vis[v] = true;
  tin[v] = low[v] = timer++;
  for (int to : x[v])
  {
    if (to == p)
      continue;
    if (vis[to])
    {
      low[v] = min(low[v], tin[to]);
    }
    else
    {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v])
      {
        bridge[{to, v}] = bridge[{v, to}] = true;
      }
    }
  }
}

int strong_comps(int u)
{
  vis[u] = 2;
  int ret = 1;
  for (auto i : x[u])
  {
    if (!bridge[{u, i}] && vis[i] < 2)
      ret += strong_comps(i);
  }
  return ret;
}

pair<int, int> edge[N];

void dfs2(int u, int p = -1)
{
  vis[u] = 3;
  for (auto i : x[u])
  {
    if (bridge[{u, i}])
      continue;
    bridge[{i, u}] = bridge[{u, i}] = true;
    edge[edgeNum[{u, i}]] = {i, u};
    if (vis[i] < 3)
      dfs2(i, u);
  }
}

int main()
{
  Speed;

  int m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    edgeNum[{u, v}] = edgeNum[{v, u}] = i;
    x[u].push_back(v);
    x[v].push_back(u);
  }

  memset(vis, false, sizeof vis);
  memset(tin, -1, sizeof tin);
  memset(low, -1, sizeof low);

  dfs(1);

  int maxR = 0, ind = -1;
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] < 2)
    {
      int r = strong_comps(i);
      if (r > maxR)
      {
        maxR = r;
        ind = i;
      }
    }
  }

  bridge.clear();
  dfs2(ind);

  cout << maxR << endl;
  for (int i = 1; i <= m; i++)
    cout << edge[i].first << " " << edge[i].second << endl;

  return 0;
}