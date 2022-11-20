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

  ll t = 1, tt = 1;

  while (t--)
  {
    ll n;
    cin >> n;

    ll a[n], mx = 0, idx = 0;
    map<ll, ll> mp;

    vector<ll> ans;

    for (ll i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
      mp[a[i]] = mp[a[i] - 1] + 1;
      if (mx < mp[a[i]])
      {
        mx = mp[a[i]];
        idx = a[i];
      }
    }

    ll x = idx - mx + 1;
    for (ll i = 0; i < n; i++)
    {
      if (a[i] == x)
        ans.push_back(i + 1), x++;
      if (x > idx)
        break;
    }

    cout << mx << endl;
    for (auto i : ans)
      cout << i << ' ';
  }
  cout << endl;
  return 0;
}
