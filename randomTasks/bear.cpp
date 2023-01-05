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
  int l, b;
  cin >> l >> b;
  int c = 0;
  while (l<=b) {
    l *= 3;
    b *= 2;
    c++;
  }
  cout << c << endl;
  return 0;
}
