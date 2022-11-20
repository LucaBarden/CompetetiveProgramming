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
#define sc stack<char>
#define pb push_back
#define print(i) cout << i << endl

void printPairs(int arr[], int arr_size, int sum)
{
  unordered_set<int> s;
  for (int i = 0; i < arr_size; i++)
  {
    int temp = sum - arr[i];

    if (s.find(temp) != s.end())
    {
      cout << "Yes" << endl;
      return;
    }
    s.insert(arr[i]);
  }
  cout << "No" << endl;
}

signed main()
{
  CIN;
  int n, m;
  cin >> n >> m;
  int A[n];
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  int size = sizeof(A) / sizeof(A[0]);

  printPairs(A, size, m);

  return 0;
}
