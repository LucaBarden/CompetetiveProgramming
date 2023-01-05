#include <bits/stdc++.h>

using namespace std;

#define Speed                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl
#define x first
#define y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;



signed main()
{
  Speed;
  int n;
  cin >> n;
  int c = 0;
  while (n > 0) {
    n -= 5;
    c++;
  }
  cout << c << endl;
  return 0;
}
