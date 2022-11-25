#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define Faster                  \
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

int N;

const char cmds[] = "RPS";

bool init()
{
  cin >> N;
  return N != 0;
}

int log3(int x)
{
  int ret = 1;
  for (; ret <= x; ret *= 3)
    ;
  return ret / 3;
}

int rec(int x)
{
  if (x < 3)
  {
    return x;
  };
  int log = log3(x);
  return (rec(x - log) + 1) % 3;
}

void solve()
{
  putchar(cmds[(rec(N - 1) + 1) % 3]);
  puts("");
}

signed main()
{
  Faster;
  while (init())
  {
    solve();
  }
  return 0;
}
