#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pf printf
#define ull unsigned long long
#define CIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define db double
#define ft float
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vi>
#define FOR(i, j, k, in) for (int i=j ; i<=k ; i+=in)
#define vs vector<string>
#define vpp vector<pi>

const int M = 100000000;
const int N = 1e3 + 7;

ll n, m, cursz = 0, col = 0;
ll comp[N][N], sz[N], vis[N][N], store[N];
char a[N][N];
int dx[4] = { -1, +1, 0, 0};
int dy[4] = {0, 0, +1, -1};

void dfs(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
        return;
    if (a[i][j] == '*')
        return;
    if (vis[i][j])
        return;
    cursz++;
    vis[i][j] = 1;
    comp[i][j] = col;
    FOR(k,0,3,1)
        dfs(i + dx[k], j + dy[k]);
}

void yash()
{
    cin >> n >> m;
    FOR(i,1,n,1)
        FOR(j,1,m,1)
            cin >> a[i][j];
    FOR(i,1,n,1)
    {
        FOR(j,1,m,1)
        {
            if (!vis[i][j])
            {
                ++col;
                cursz = 0;
                dfs(i, j);
                store[col] = cursz;
            }
        }
    }
    FOR(i,1,n,1)
    {
        FOR(j,1,m,1)
        {
            if (a[i][j] == '.')
            {
                cout << ".";
                continue;
            }
            set<int> s;
            int ans = 1;
            FOR(k,0,3,1)
                s.insert(comp[i + dx[k]][j + dy[k]]);
            for (auto &it : s)
                ans += store[it];
            ans %= 10;
            cout << ans;
        }
        cout << endl;
    }
}

signed main()
{
    CIN;
    yash();
    return 0;
}
