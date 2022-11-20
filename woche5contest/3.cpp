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
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (is_sorted(s.begin(), s.end()))
    {
      cout << 0 << endl;
      continue;
    }

    string t = s;
    sort(t.begin(), t.end());
    cout << 1 << endl;
    vi ans;
    for (int i = 0; i < n; i++)
    {
      if (s[i] != t[i])
        ans.pb(i + 1);
    }
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
  return 0;
}
