#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define CIN                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
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
#define N 10005

const int OO = 1e9;

struct BIT
{
  vi v;
  int n;

  BIT(int n_)
  {
    v.resize((1 << (__lg(n_) + 1)) + 1);
    n = 1 << (__lg(n_) + 1);
  }

  int query(int k)
  {
    int sum = 0;
    while (k >= 1)
    {
      sum += v[k];
      k -= k & -k;
    }
    return sum;
  }

  void update(int k, int x)
  {
    while (k <= n)
    {
      v[k] += x;
      k += k & -k;
    }
  }

  int lower_bound(int val)
  {
    int sum = 0, pos = 0;

    for (int i = __lg(n); i >= 0; i--)
    {
      int step = 1 << i;
      if (sum + v[pos + step] < val)
      {
        sum += v[pos + step];
        pos += step;
      }
    }
    return pos + 1;
  }

  int range(int l, int r)
  {
    return query(r) - query(l - 1);
  }
};

signed main()
{
  CIN;
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  vector<BIT> bits(m, BIT(n));

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    bits[a[i] % m].update(i, a[i]);
  }

  int q;
  cin >> q;

  while (q--)
  {
    char c;
    cin >> c;
    if (c == 's')
    {
      int l, r, mod;
      cin >> l >> r >> mod;
      cout << bits[mod].range(l, r) << endl;
    }
    else if (c == '+')
    {
      int p, r;
      cin >> p >> r;
      int oldVal = a[p];
      int newVal = a[p] + r;

      bits[oldVal % m].update(p, -oldVal);
      bits[newVal % m].update(p, newVal);
      a[p] = newVal;
      cout << a[p] << endl;
    }
    else if (c == '-')
    {
      int p, r;
      cin >> p >> r;
      int oldVal = a[p];
      int newVal = a[p] - r;
      if (newVal < 0)
      {
        cout << a[p] << endl;
        continue;
      }

      bits[oldVal % m].update(p, -oldVal);
      bits[newVal % m].update(p, newVal);
      a[p] = newVal;
      cout << a[p] << endl;
    }
  }
}
