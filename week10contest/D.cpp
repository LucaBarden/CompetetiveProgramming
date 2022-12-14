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
typedef pair<int, int> ii;

vi out[200050];
bool vis[200050];
vi adj[200050];
vi T[200050];
vi backedges[200050];

void dfs(int u, int p)
{
  vis[u] = true;
  for (int v : adj[u])
  {
    if (v == p)
      continue;
    if (vis[v])
    {
      backedges[u].pb(v);
    }
    else
    {
      T[u].pb(v);
      dfs(v, u);
    }
  }
}

void dfs2(int u, int p)
{
  for (int v : T[u])
  {
    dfs2(v, u);
  }
  if (p == -1)
    return;
  if (out[u].size() % 2 == 1)
    out[u].pb(p);
  else
    out[p].pb(u);
}

signed main()
{
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vi roots;
  for (int i = 1; i <= N; i++)
  {
    if (!vis[i])
    {
      dfs(i, -1);
      roots.pb(i);
    }
  }
  for (int i = 1; i <= N; i++)
  {
    for (int v : backedges[i])
    {
      if (i < v)
        out[i].pb(v);
    }
  }
  for (int r : roots)
  {
    dfs2(r, -1);
  }
  vector<vi> ans;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 0; j < out[i].size(); j += 2)
    {
      if (j + 1 < out[i].size())
        ans.pb({out[i][j], i, out[i][j + 1]});
    }
  }
  cout << ans.size() << endl;
  for (vi i : ans)
    cout << i[0] << " " << i[1] << " " << i[2] << endl;
}