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

int n, m;
vector<vector<int>> g;
vector<int> used;
string s;

vector<vector<int>> dp;
void dfs(int v)
{
  used[v] = 1;
  for (auto &ch : g[v])
  {
    if (used[ch] == 1)
    {
      cout << -1 << endl;
      exit(0);
    }
    if (used[ch] == 0)
    {
      dfs(ch);
    }
    for (int i = 0; i < 26; i++)
    {
      dp[v][i] = max(dp[v][i], dp[ch][i]);
    }
  }
  used[v] = 2;
  dp[v][s[v] - 'a']++;
}

void solve()
{
  cin >> n >> m >> s;
  g.resize(n, vector<int>());
  used.resize(n);
  dp.resize(n, vector<int>(26));
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (!used[i])
    {
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}

signed main()
{
  CIN;
  solve();
}