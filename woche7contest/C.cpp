#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100000 + 3;
const int INF = 1e9 + 10;

struct edge
{
  int tar, cost;
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

int euler_tour[2 * MAX_V - 1];
int depth[2 * MAX_V - 1];
int first_occur[MAX_V];
vector<int> tree[MAX_V];

void dfs_LCA(int v, int par, int d, int &e)
{
  first_occur[v] = e;
  euler_tour[e] = v;
  depth[e++] = d;
  for (int i = 0; i < (int)tree[v].size(); i++)
  {
    const int u = tree[v][i];
    if (u != par)
    {
      dfs_LCA(u, v, d + 1, e);
      euler_tour[e] = v;
      depth[e++] = d;
    }
  }
}

void build_LCA(int root)
{
  int e = 0;
  dfs_LCA(root, -1, 0, e);

  for (int i = 0; i < 2 * V - 1; i++)
  {
    rmq.rmq_data[i] = depth[i];
  }
  rmq.build_rmq(2 * V - 1);
}

int query_LCA(int u, int v)
{
  return euler_tour[rmq.query(min(first_occur[u], first_occur[v]), max(first_occur[u], first_occur[v]) + 1)];
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

  bool dbl = dict.size() == V - 1;
  for (map<pair<int, int>, int>::iterator itr = dict.begin(); itr != dict.end(); itr++)
  {
    int x = itr->first.first, y = itr->first.second, z = itr->second;
    graph[x].push_back((edge){y, z});
    graph[y].push_back((edge){x, z});
    degs[x]++;
    degs[y]++;
  }
  if (dbl)
  {
    graph[0].push_back((edge){V, 0});
    graph[0].push_back((edge){V, 0});
    graph[V].push_back((edge){0, 0});
    graph[V].push_back((edge){V + 1, 0});
    graph[V + 1].push_back((edge){0, 0});
    graph[V + 1].push_back((edge){V, 0});
    degs[0] += 2;
    degs[V] += 2;
    degs[V + 1] += 2;
    V += 2;
  }
  cin >> Q;

  return V > 0;
}

void dfs_dist(int v)
{
  visited[v] = true;
  for (int i = 0; i < (int)graph[v].size(); i++)
  {
    const int u = graph[v][i].tar;
    if (!visited[u] && parent[v] == parent[u])
    {
      dist[u] = dist[v] + graph[v][i].cost;
      dfs_dist(u);
    }
  }
}

int get_length_on_cycle(int v, int u)
{
  int a = min(to_idx[v], to_idx[u]) - 1, b = max(to_idx[v], to_idx[u]) - 1;
  return min(accum[b] - accum[a], accum[C] - (accum[b] - accum[a]));
}

void dfs_path(int v, int p)
{
  if (visited[v])
  {
    return;
  }
  C = p;
  visited[v] = true;
  to_idx[v] = p;

  for (int i = 0; i < (int)graph[v].size(); i++)
  {
    const int u = graph[v][i].tar;
    if (!visited[u] && parent[u] == u)
    {
      accum[p] = accum[p - 1] + graph[v][i].cost;
      dfs_path(u, p + 1);
      return;
    }
  }

  for (int i = 0; i < (int)graph[v].size(); i++)
  {
    const int u = graph[v][i].tar;
    if (to_idx[u] == 1)
    {
      accum[p] = accum[p - 1] + graph[v][i].cost;
      return;
    }
  }
}

void dfs_parent(int v, int p)
{
  parent[v] = p;
  for (int i = 0; i < (int)graph[v].size(); i++)
  {
    const int u = graph[v][i].tar;
    if (parent[u] == -1)
    {
      dfs_parent(u, p);
    }
  }
}

void prepare()
{
  // サイクル上のパスを計算するための準備
  memset(visited, false, sizeof(visited));
  queue<int> que;
  for (int i = 0; i < V; i++)
    if (degs[i] == 1)
    {
      que.push(i);
      visited[i] = true;
    }
  while (!que.empty())
  {
    int v = que.front();
    que.pop();
    visited[v] = true;
    for (int i = 0; i < (int)graph[v].size(); i++)
    {
      const int u = graph[v][i].tar;
      if (--degs[u] == 1)
      {
        que.push(u);
      }
    }
  }

  int key = -1;
  for (int i = 0; i < V; i++)
    if (!visited[i] && degs[i] == 2)
    {
      parent[i] = i;
      key = i;
    }

  memset(visited, false, sizeof(visited));
  dfs_path(key, 1);
  for (int i = 0; i < V; i++)
    if (parent[i] == i)
    {
      dfs_parent(i, i);
    }

  // ダミーノードを追加してLCAを構成する
  V++;
  parent[V - 1] = V - 1;
  for (int i = 0; i < V; i++)
  {
    tree[i].clear();
  }
  for (int i = 0; i < V - 1; i++)
    if (parent[i] == i)
    {
      tree[V - 1].push_back(i);
      tree[i].push_back(V - 1);
    }

  for (int i = 0; i < V - 1; i++)
  {
    for (int j = 0; j < (int)graph[i].size(); j++)
    {
      const int u = graph[i][j].tar;
      if (parent[i] == parent[u])
      {
        tree[i].push_back(u);
      }
    }
  }

  build_LCA(V - 1);

  memset(visited, 0, sizeof(visited));
  dist[V - 1] = 0;
  for (int i = 0; i < V - 1; i++)
    if (parent[i] == i)
    {
      dist[i] = 0;
      dfs_dist(i);
    }
}

int query()
{
  int x, y;
  cin >> x >> y;
  if (parent[x] == parent[y])
  {
    return dist[x] + dist[y] - 2 * dist[query_LCA(x, y)];
  }
  else
  {
    return dist[x] + dist[y] + get_length_on_cycle(parent[x], parent[y]);
  }
}

int main()
{
  while (init())
  {
    prepare();
    for (int i = 0; i < Q; i++)
    {
      cout << query() << endl;
    }
  }

  return 0;
}