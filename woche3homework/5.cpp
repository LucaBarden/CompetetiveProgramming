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

ll int mx = 1000007;

ll int sum[1000007];

int main()
{
  CIN;
  ll int n, m, a, b, c, d, cnt = 0;

  cin >> a >> b >> c >> d;

  for (int i = a; i <= b; i++)
  {
    sum[i + b]++;
    sum[i + c + 1]--;
  }
  for (int i = 1; i < mx; i++)
  {
    sum[i] += sum[i - 1];
  }

  for (int i = 1; i < mx; i++)
  {
    sum[i] += sum[i - 1];
  }

  for (int i = c; i <= d; i++)
  {
    cnt += sum[mx - 1] - sum[i];
  }
  cout << cnt << endl;

  return 0;
}
