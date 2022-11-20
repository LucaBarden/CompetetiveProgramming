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
const int N = 1e5 + 5;
double a[N];

signed main()
{
  CIN;
  int n, x;
  cin >> n >> x;
  double sum = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i] * a[i];
  }
  if (x == 0 || sum == 0 || n == 0)
  {
    for (int i = 0; i < n; i++)
    {
      printf("%d ", a[i]);
    }
  }
  else
  {
    double k = sqrt(1.0 * sum / n / x);
    for (int i = 0; i < n; i++)
      printf("%.9f ", (double)1.0 * a[i] / k);
  }
  return 0;
}
