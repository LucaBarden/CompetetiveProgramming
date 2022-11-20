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
const int N = 1e5 + 10;
ll int a[N];
ll int b[N];
ll int c[N];
struct P
{
  ll l;
  ll r;
  ll d;
  ll count;
} z[N];

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    b[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= m; i++)
  {
    cin >> z[i].l >> z[i].r >> z[i].d;
  }
  int x, y;
  for (int i = 1; i <= k; i++)
  {
    cin >> x >> y;
    c[x]++;
    c[y + 1]--;
  }
  for (int i = 1; i <= m; i++)
  {
    c[i] += c[i - 1];
    z[i].count = c[i];
    b[z[i].l] += z[i].d * z[i].count;
    b[z[i].r + 1] -= z[i].d * z[i].count;
  }
  for (int i = 1; i <= n; i++)
  {
    a[i] = a[i - 1] + b[i];
    cout << a[i] << " ";
  }
  cout << endl;
}
