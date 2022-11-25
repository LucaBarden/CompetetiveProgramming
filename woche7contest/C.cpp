#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define Faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define mod 1000000007
#define ld long double
#define ft float
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pii pair<int, int>
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

const int MAX_V = 10005;
const int INF = 1e9 + 10;

struct edge
{
  int target;
  int cost;
};

int V, Q, C;

vector<edge> graph[MAX_V];
int parent[MAX_V];
int dist[MAX_V];
int degs[MAX_V];
int to_idx[MAX_V];
int accum[MAX_V + 1];
bool visited[MAX_V];

struct RangeMinimumQuery
{

  static const int MAX_RMQ = 2 * MAX_V - 1;
  static const int MAX_LOG = 20;

  int RMQ_SIZE;
  typedef int rmq_t;

  rmq_t rmq_data[MAX_RMQ];
  rmq_t sparse_table[MAX_LOG + 1][MAX_RMQ];

  void build_rmq(int N)
  {
    RMQ_SIZE = N;
    const int log_rmq = 31 - __builtin_clz(RMQ_SIZE);

    for (int i = 0; i < RMQ_SIZE; i++)
    {
      sparse_table[0][i] = i;
    }

    for (int i = 0; i < log_rmq; i++)
    {
      for (int j = 0, stp = RMQ_SIZE - (1 << (i + 1)) + 1; j < stp; j++)
      {
        const int prev = sparse_table[i][j], post = sparse_table[i][j + (1 << i)];
        sparse_table[i + 1][j] = (rmq_data[prev] > rmq_data[post] ? post : prev);
      }
    }
  }

  int query(int from, int to)
  {
    const int log_d = 31 - __builtin_clz(to - from);
    const int prev = sparse_table[log_d][from], post = sparse_table[log_d][to - (1 << log_d)];
    return rmq_data[prev] > rmq_data[post] ? post : prev;
  }
};

RangeMinimumQuery rmq;

int tour[2 * MAX_V - 1];
int depth[2 * MAX_V - 1];
int first_occur[MAX_V];
vector<int> tree[MAX_V];

void dfs(int v, int par, int d, int &e)
{
  first_occur[v] = e;
  tour[e] = v;
  depth[e++] = d;
  for (int i = 0; i < (int)tree[v].size(); i++)
  {
    const int u = tree[v][i];
    if (u != par)
    {
      dfs(u, v, d + 1, e);
      tour[e] = v;
      depth[e++] = d;
    }
  }
}

void build(int root)
{
  int e = 0;
  dfs(root, -1, 0, e);
  for (int i = 0; i < 2 * V - 1; i++)
  {
    rmq.rmq_data[i] = depth[i];
  }
  rmq.build_rmq(2 * V - 1);
}

int query(int u, int v)
{
  return tour[rmq.query(min(first_occur[u], first_occur[v]), max(first_occur[u], first_occur[v]) + 1)];
}

bool init()
{
  cin >> V;
  for (int i = 0; i <= V + 2; i++)
  {
    graph[i].clear();
  }
  memset(parent, -1, sizeof(parent));
  memset(to_idx, -1, sizeof(to_idx));
  memset(degs, 0, sizeof(degs));
  map<pair<int, int>, int> dict;

  for (int i = 0; i < V; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    if (x > y)
    {
      swap(x, y);
    }
    if (dict.find(make_pair(x, y)) == dict.end())
    {
      dict[make_pair(x, y)] = z;
    }
    else
    {
      dict[make_pair(x, y)] = min(dict[make_pair(x, y)], z);
    }
  }
}

signed main()
{
  Faster;
  return 0;
}
