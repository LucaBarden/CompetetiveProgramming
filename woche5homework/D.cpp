#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define ull unsigned long long
#define CIN                       \
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

signed main()
{
    CIN;
    int n;
    cin >> n;
    int intervals = 0;
    int start = 0;
    string res;
    for (int i = 1; i <= n; i++)
    {
        cout << "? " << start << " " << i << endl;
        cin >> res;
        if (res == "absent")
        {
            intervals++;
            start = i;
        }
    }
    cout << "! " << intervals << endl;
    return 0;
}
