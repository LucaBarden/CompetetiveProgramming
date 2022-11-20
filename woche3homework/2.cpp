#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pf printf
#define ull unsigned long long
#define CIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define mod 1000000007
#define db double
#define ft float
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vi>
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define vs vector<string>
#define vpp vector<pi>

const int M = 100000000;
const int N = 100000;

signed main()
{
    CIN;
    ll t;
    t = 1;

    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        if (2 * n <= s)
        {
            cout << "YES" << endl;
            int temp = s - 2 * (n - 1);
            cout << temp << " ";
            for (int i = 0; i < n - 1; i++)
            {
                cout << 2 << " ";
            }
            cout << endl;
            cout << s - 1 << endl;
            return 0;
        }
        cout << "NO";
    }
    cout << endl;

    return 0;
}
