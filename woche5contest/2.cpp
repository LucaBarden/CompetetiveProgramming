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

signed main()
{
  CIN;
  ll t;
  int n;
  vi vec;
  cin >> t;

  while (t--)
  {
    cin >> n;

    vec.resize(n);
    for (auto &c : vec)
      cin >> c;

    sort(vec.begin(), vec.end());

    cout << vec[n - 1] + vec[n - 2] - vec[0] - vec[1] << endl;
  }

  return 0;
}
