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

const int MAX_N = 1000;
const int MOD = 1e9 + 7;

int comb[2 * MAX_N + 1][2 * MAX_N + 1];
int memo[MAX_N + 1];
int N;
bool visited[MAX_N + 1];

bool init()
{
  cin >> N;
  return N > 0;
}

int rec(int n)
{
  if (visited[n])
  {
    return memo[n];
  }
  visited[n] = true;

  int &ret = memo[n] = 0;
  if (n == 0)
  {
    return ret = 1;
  }
  ret = 2 * (2 * n - 1) % MOD;
  ret *= rec(n - 1);
  ret %= MOD;

  return ret;
}

int solve()
{
  int ret = 0;
  for (int i = 0; i < N; i++)
  {
    int add = 2 * (2 * N - 1);
    add *= comb[2 * N - 2][2 * i];
    add %= MOD;
    add *= rec(i);
    add %= MOD;
    add *= rec(N - 1 - i);
    add %= MOD;

    ret = (ret + add) % MOD;
  }

  return ret;
}

void pre()
{
  comb[0][0] = 1;
  for (int i = 0; i <= 2 * MAX_N; i++)
  {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 0; j < i; j++)
    {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
  }
}

signed main()
{
  Faster;
  pre();
  while (init())
  {
    cout << solve() << endl;
  }

  return 0;
}
