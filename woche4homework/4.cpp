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

string s;
int arr[26], dp[1005], dp2[1005];
signed main()
{
  int n, l = 0;
  cin >> n >> s;
  for (int i = 0; i < 26; i++)
    cin >> arr[i];
  dp[0] = 1;
  dp2[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    int f = 0;
    dp2[i] = n;
    for (int x = i - 1; x >= 0; x--)
    {
      f = max(f, i - arr[s[x] - 'a']);
      if (f > x)
        continue;
      dp[i] = (dp[i] + dp[x]) % mod;
      dp2[i] = min(dp2[i], 1 + dp2[x]);
      l = max(l, i - x);
    }
  }
  cout << dp[n] << endl
       << l << endl
       << dp2[n] << endl;
}