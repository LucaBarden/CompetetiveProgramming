#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl
#define x first
#define y second
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int maxn = 1e5 + 5;
set<int> st, graph[maxn];
int n, m, cnt;

void dfs(int u)
{
  st.erase(u);
  set<int>::iterator it;
  int v = 0;
  while ((it = st.upper_bound(v)) != st.end())
  {
    v = *it;
    if (graph[u].count(v))
      continue;
    dfs(v);
  }
}

signed main()
{
  Speed;
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    graph[x].insert(y);
    graph[y].insert(x);
  }
  for (int i = 1; i <= n; i++)
    st.insert(i);
  for (int i = 1; i <= n; i++)
    if (st.count(i))
      cnt++, dfs(i);
  cout << cnt - 1 << endl;
  return 0;
}