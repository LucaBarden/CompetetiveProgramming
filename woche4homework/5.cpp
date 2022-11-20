#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define dl long double
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

signed main()
{
  CIN;

  int n, k;
  cin >> n >> k;

  map<int, int> left, right;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    right[a[i]]++;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    right[a[i]]--;
    if (abs(a[i]) % k == 0)
    {
      int l = (left.count(a[i] / k) ? left[a[i] / k] : 0);
      int r = (right.count(a[i] * k) ? right[a[i] * k] : 0);
      ans += l * r;
    }
    left[a[i]]++;
  }

  cout << ans << endl;

  return 0;
}
