#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define CIN                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
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

const int N = 2000;
const ld eps = 1e-9;
ll mod;
const ll inf = 1e18 + 5;

int n, m, k;

ll DP[N][100];

ll mul(ll a, ll b, ll mod)
{
  ll rta = a * b;
  return rta >= mod ? rta % mod : rta;
}

ll sum(ll a, ll b, ll mod)
{
  ll rta = a + b;
  return rta >= mod ? rta - mod : rta;
}

ll elev(ll b, int e, ll mod)
{
  ll rta = 1;
  while (e)
  {
    if (e & 1)
    {
      rta = mul(b, rta, mod);
    }
    b = mul(b, b, mod);
    e >>= 1;
  }
  return rta;
}
ll dp(int i, int j, bool ya)
{
  if (i == n)
    return j == 0 && ya;
  if (j == 0 && ya)
    return mul(9, elev(10, n - i - 1, mod), mod);
  if (DP[i][j] != -1 && ya)
    return DP[i][j];
  ll rta = 0;
  for (int l = 0; l < 10; ++l)
  {
    rta = sum(rta, dp(i + 1, sum(j, mul(l, elev(10, i, k), k), k), ya || l), mod);
  }
  if (ya)
    return DP[i][j] = rta;
  return rta;
}

signed main()
{
  CIN;
  int a, l, T;
  memset(DP, -1, sizeof DP);
  cin >> n >> k >> mod;
  ll rta = dp(0, 0, 0);
  cout << rta << endl;
}
