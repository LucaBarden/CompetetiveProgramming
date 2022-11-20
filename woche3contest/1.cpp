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
  string s;
  cin >> s;
  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3, 2));
  for (int ans = 0; ans <= 24 * 60; ans++)
  {
    if (h % 10 * 10 + h / 10 == m)
    {
      cout << ans << endl;
      break;
    }
    m++;
    h += m / 60;
    m %= 60;
    h %= 24;
  }

  return 0;
}
