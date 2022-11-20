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
const int N = 2e5 + 10;

int f[N];
pii ans;
int T;
int cnt;

bool check(int x)
{
  cnt++;
  if (cnt > 11190)
    while (1)
      ;
  cout << "? " << f[T] << " " << x << endl;
  string a;
  cin >> a;
  if (a == "sky")
    return 0;
  else
    return 1;
}

signed main()
{
  CIN;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    f[i] = i;
  }
  ans.first = 1;
  cnt = 0;
  srand(time(0));
  random_shuffle(f + 1, f + n + 1);
  for (int i = 1; i <= n; i++)
  {
    T = i;
    int l = min(ans.second + 1, m), r = m;
    if (!check(l))
      continue;
    else
      ans.first = f[i], ans.second = l;
    while (l < r)
    {
      int mid = l + r + 1 >> 1;
      if (check(mid))
        ans.first = f[i], ans.second = mid, l = mid;
      else
        r = mid - 1;
    }
  }
  cout << "! " << ans.first << " " << ans.second << endl;
  return 0;
}
