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

const int N = 1e5 + 10;
double x[N], y[N];
const double pi = acos(-1.0);

void solve()
{
  int n;
  cin >> n;
  for (size_t i = 1; i <= n; i++)
  {
    cin >> x[i] >> y[i];
  }
  double res = 0;
  double maxx = x[1] * 1.0, maxy = y[1] * 1.0;
  for (int i = 2; i < n; i++)
  {
    double tann = 0;
    if (y[i] > maxy)
    {
      tann = (y[i] - maxy) / (x[i] - maxx);
      res = max(res, (y[i] - maxy) / (x[i] - maxx));
    }
    if (maxy / tann > maxx)
    {
      maxy = y[i];
      maxx = x[i];
    }
  }
  maxx = x[n], maxy = y[n];
  for (int i = n - 1; i > 1; i--)
  {
    double tann = 0;
    if (y[i] > maxy)
    {
      tann = (y[i] - maxy) / (-x[i] + maxx);
      res = max(res, (y[i] - maxy) / (maxx - x[i]));
    }
    if (maxy / tann > maxx)
    {
      maxy = y[i];
      maxx = x[i];
    }
  }

  cout << fixed << setprecision(8) << atan(res) * 180 / pi << endl;
}

signed main()
{
  CIN;
  int T;
  T = 1;
  while (T--)
  {
    solve();
  }

  return 0;
}
