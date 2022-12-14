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

const int MAXN = 3e4 + 5;

vi N[MAXN];
bool mark[MAXN];
vi rev;

void sfd(int v)
{
  mark[v] = 1;
  for (int u : N[v])
  {
    if (!mark[u])
      sfd(u);
  }
  rev.pb(v);
}

signed main()
{
  Speed;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    N[x].pb(y);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!mark[i])
      sfd(i);
  }

  for (int u : rev)
    cout << u << " ";
  cout << endl;

  return 0;
}
