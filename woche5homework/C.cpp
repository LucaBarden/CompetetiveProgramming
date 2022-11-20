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

constexpr int N = 2200;
double dp[N], f[N];

signed main()
{
  CIN;
  int n, t, r;
  cin >> n >> t >> r;
  double p;
  cin >> p;
  for (int i = 1; i <= n; i++)
  {
    f[i] = (f[i - 1] + 1 + p * r) / (1 - p);
    dp[i] = f[i];
    for (int j = 1; j <= i; j++)
    {
      dp[i] = min(dp[i], dp[j] + t + f[i - j]);
    }
  }
  cout << fixed << setprecision(9) << dp[n] + t << endl;
  return 0;
}
