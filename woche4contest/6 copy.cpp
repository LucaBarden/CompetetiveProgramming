#include <bits/stdc++.h>

using namespace std;
#define int long long

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
  int n, m;
  cin >> m >> n;
  int A[n];
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  int arr_size = sizeof(A) / sizeof(A[0]);

  printPairs(A, arr_size, n);

  return 0;
}
