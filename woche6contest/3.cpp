#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define CIN                     \
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

#define shift(mask, i) ((mask >> i) & 1)
#define inf 2000000000000000000LL

const int maxBits = 63;

int DP[maxBits + 1][maxBits + 1];

int countBits(int x)
{
  int res = 0;
  for (; x; x &= (x - 1))
    res++;
  return res;
}

int solve(int x, int k)
{
  int ans = (countBits(x) == k);
  for (int i = maxBits; i >= 0 && k >= 0; i--)
  {
    if (shift(x, i))
      ans += DP[i][k--];
  }
  return ans;
}

signed main()
{
  CIN;
  DP[0][0] = 1;
  for (int i = 1; i <= maxBits; i++)
    for (int j = 0; j <= i; j++)
      DP[i][j] = DP[i - 1][j] + ((j) ? (DP[i - 1][j - 1]) : 0);

  int count;
  int k;
  cin >> count >> k;
  int l = 1;
  int r = inf / 2;
  while (l < r)
  {
    int m = l + (r - l) / 2;
    if (solve(m * 2, k) - solve(m, k) < count)
      l = m + 1;
    else
      r = m;
  }
  cout << l << endl;
  return 0;
}
