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

int minimizeSegment(vector<pair<int, int>> A,
                    pair<int, int> X)
{
  sort(A.begin(), A.end());

  A.push_back({INT_MAX, INT_MAX});

  int start = X.first;

  int end = X.first - 1;

  int cnt = 0;

  for (int i = 0; i < A.size();)
  {

    if (A[i].first <= start)
    {
      end = max(A[i++].second, end);
    }
    else
    {

      start = end;

      ++cnt;
      if (A[i].first > end || end >= X.second)
      {
        break;
      }
    }
  }

  if (end < X.second)
  {
    return -1;
  }

  return cnt;
}

signed main()
{
  vector<pair<int, int>> A = {
      {1, 3}, {2, 4}, {2, 10}, {2, 3}, {1, 1}};
  pair<int, int> X = {1, 10};
  cout << minimizeSegment(A, X);

  return 0;
}
