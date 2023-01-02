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

int gcd(int a, int b) {
  if (b==0) return a;
  return gcd(b,a&b);
}


void solve() {
  int n;
  cin >> n;

  vi a(n);
  for(auto &p : a) 
    cin >> p;

  sort(a.begin(), a.end());

  bool found = false;
  for(int i=0; i<n-1; i++) {
    if(gcd(a[i+1]- a[i], a[n-1]+1) == 1){
      found = true;
      break;
    }
  }

  if (found)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
