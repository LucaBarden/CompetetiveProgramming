#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pf printf
#define ull unsigned long long
#define CIN                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define mod 1000000007
#define db double
#define ft float
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vi>
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define vs vector<string>
#define vpp vector<pi>

const int M = 100000000;
const int N = 100000;

int main()
{
  CIN;
  ll m, l, r, count = 0;

  ll dp[100005];
  string s;

  cin >> s >> m;

  for (ll i = 1; i < s.size(); i++)
  {

    if (s[i] == s[i - 1])
      count++;

    dp[i] = count;
  }

  while (m--)
  {
    cin >> l >> r;
    cout << dp[r - 1] - dp[l - 1] << endl;
  }
  return 0;
}
