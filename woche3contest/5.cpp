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

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n % 4 != 0)
      cout << "NO" << endl;
    else
    {
      cout << "YES" << endl;
      for (int i = 1; i <= n / 2; i++)
      {
        cout << i * 2 << " ";
      }
      int j = 1;
      for (int i = 1; i < n / 2; i++)
      {
        cout << j << " ";
        j += 2;
      }
      ll sm = ((ll)n / 2) * ((ll)n / 2 + 1);
      cout << sm - ((ll)(n / 2 - 1) * (ll)(n / 2 - 1)) << endl;
    }
  }

  return 0;
}
