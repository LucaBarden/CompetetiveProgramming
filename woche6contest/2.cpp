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

signed main()
{
  CIN;
  int a;
  int b;
  int ans = 0;

  cin >> a >> b;
  if (a < b)
    swap(a, b);
  while (a % b != 0)
  {
    ans = ans + a / b;
    int bb = b;
    b = a % b;
    a = bb;
  }
  cout << ans + a << endl;
  return 0;
}
