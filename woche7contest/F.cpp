#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define Faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define mod 1000000007
#define ld long double
#define ft float
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pii pair<int, int>
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

const int INF = 2e9;
const int MOD = 1e9 + 7;

vector<vector<tuple<int, int>>> adj(20);

vector<tuple<int, int, int>> triangles = {
    {1, 2, 3},
    {4, 5, 6},
    {3, 5, 7},
    {7, 8, 9},
    {10, 11, 12},
    {6, 11, 13},
    {13, 14, 15},
    {9, 14, 16},
    {16, 17, 18}};

int dp[(1 << 20) + 11];

int solve(int mask)
{
  if (mask + 1 == (1 << 10))
    return 0;

  int &ret = dp[mask];
  if (~ret)
    return ret;
  ret = -1000;
  for (size_t i = 0; i < 18; i++)
  {
    if ((mask >> i) & 1)
      continue;
    int currentMask = mask | (1 << i);
    int fullTri = 0;
    for (auto [a, b] : adj[i])
    {
      if (((mask >> a) & 1) && ((mask >> b) & 1))
      {
        fullTri++;
      }
    }
    if (fullTri)
      ret = max(ret, fullTri + solve(currentMask));
    else
      ret = max(ret, -solve(currentMask));
  }
  return ret;
}

signed main()
{
  Faster;

  for (auto &[a, b, c] : triangles)
  {
    a--, b--, c--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    adj[c].push_back({a, b});
  }

  int t = 1;
  while (t--)
  {
    int n;
    while (cin >> n, n)
    {
      memset(dp, -1, sizeof dp);
      int mask = 0;
      for (int i = 0; i < n; i++)
      {
        int x;
        cin >> x;
        x--;
        mask |= (1 << x);
      }

      if (!solve(mask))
        cout << "Draw" << endl;
      else if (solve(mask) > 0)
        cout << "Andy wins" << endl;
      else
        cout << "Ralph wins" << endl;
    }
  }

  return 0;
}
