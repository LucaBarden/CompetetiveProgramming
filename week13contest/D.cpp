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

const int maxn = 1e5 + 5;
vi graph[maxn];

void solve()
{
  int n;
  cin >> n;
  for (auto i = 1; i <= n; i++)
    graph[i].clear();
  int x, y, z;
  for (auto i = 1; i < n; i++)
  {
    cin >> x >> y >> z;
    graph[x].pb(z);
    graph[y].pb(z);
  }
  ll res = 0;
  for (auto i = 1; i <= n; i++)
  {
    if (graph[i].size() > 1)
    {
      sort(graph[i].begin(), graph[i].end());
      for (size_t j = 1; j < graph[i].size(); j++)
      {
        res += graph[i][0] + graph[i][j];
      }
    }
  }
  print(res);
}

signed main()
{
  Speed;
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
