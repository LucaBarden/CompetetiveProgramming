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

signed main()
{
  CIN;
  int n, m;
  cin >> n >> m;
  int nums[n];

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    char op;
    int l, r, k;
    cin >> op;
    switch (op)
    {
    case '+':
      cin >> l >> r;
      nums[l - 1] += r;
      cout << nums[l - 1] << endl;
      break;
    case '-':
      cin >> l >> r;
      if (nums[l - 1] - r < 0)
      {
        cout << nums[l - 1] << endl;
        break;
      }
      nums[l - 1] -= r;
      cout << nums[l - 1] << endl;
      break;
    case 's':
      cin >> l >> r >> k;
      int sum;
      sum = 0;
      for (int j = l; j <= r; j++)
      {
        if (j % m == k)
        {
          sum += j;
        }
      }
      cout << sum << endl;
      break;

    default:
      break;
    }
  }

  return 0;
}