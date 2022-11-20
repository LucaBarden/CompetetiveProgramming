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
  int mx = 300000, mn;
  int df[300000], in[300000];

  int n, k, q;
  cin >> n >> k >> q;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    mx = max(mx, max(x, y));
    mn = min(mn, min(x, y));
    df[x]++;
    df[y + 1]--;
  }
  if (mn > 1)
    mn--;
  for (int i = mn; i <= mx + 1; i++)
  {
    df[i] += df[i - 1];
  }
  for (int i = mn; i <= mx; i++)
  {
    in[i] = in[i - 1];
    if (df[i] >= k)
      in[i]++;
  }
  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;
    cout << in[y] - in[x - 1] << endl;
  }

  return 0;
}
