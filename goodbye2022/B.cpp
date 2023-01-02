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


void solve() {
  int n,k;
  cin >> n >> k;

  for(int i=n; i>=1; i--)
    cout << i << " ";
  cout << endl;
}



signed main()
{
  Speed;
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
