#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <queue>
#define inf 2000000000
using namespace std;
typedef pair<int, int> Pair;
typedef pair<Pair, int> PPair;

typedef struct edge
{
   int to;
   int capacity;
   edge *prev;
   edge(int to, int capacity) : to(to), capacity(capacity) {}
};

vector<vector<edge *>> adj;
vector<pair<int, int>> check;

int s, t;
int n, m;

void add_edge(int u, int v, int cap)
{
   edge *next = new edge(v, cap);
   edge *prev = new edge(u, 0);
   next->prev = prev;
   prev->prev = next;
   adj[u].push_back(next);
   adj[v].push_back(prev);
}
int bfs()
{
   queue<int> q;
   q.push(s);
   check[s].first = s;
   int flag = 1;
   while (!q.empty() && flag)
   {
      int node = q.front();
      q.pop();
      for (int i = 0; i < adj[node].size() && flag; i++)
      {
         int next_node = adj[node][i]->to;
         int cap = adj[node][i]->capacity;
         if (check[next_node].first == -1 && cap > 0)
         {
            check[next_node] = {node, i};
            q.push(next_node);
            if (next_node == t)
               flag = 0;
         }
      }
   }

   if (check[t].first == -1)
      return 0;
   int flow = inf;
   for (int i = t; i != s; i = check[i].first)
      flow = min(flow, adj[check[i].first][check[i].second]->capacity);
   for (int i = t; i != s; i = check[i].first)
   {
      adj[check[i].first][check[i].second]->capacity -= flow;
      adj[check[i].first][check[i].second]->prev->capacity += flow;
   }
   return flow;
}

int floyd[305][305];

int main(void)
{
   int tc;
   scanf("%d", &tc);
   while (tc--)
   {
      scanf("%d %d", &n, &m);
      adj.clear(), check.clear();
      adj.resize(n);
      check.resize(n, make_pair(-1, -1));
      s = 0, t = n - 1;
      vector<Pair> v;
      for (int i = 0; i < m; i++)
      {
         int a, b, c;
         scanf("%d %d %d", &a, &b, &c);
         a--, b--;
         add_edge(a, b, c);
         v.push_back({a, b});
      }
      while (1)
      {
         fill(check.begin(), check.end(), make_pair(-1, -1));
         int flow;
         flow = bfs();
         if (flow == 0)
            break;
      }

      memset(floyd, 0, sizeof(floyd));
      for (int i = 0; i < adj.size(); i++)
      {
         for (int j = 0; j < adj[i].size(); j++)
         {
            if (adj[i][j]->capacity > 0)
            {
               floyd[i][adj[i][j]->to] = 1;
            }
            if (adj[i][j]->prev->capacity > 0)
            {
               floyd[adj[i][j]->prev->to][i] = 1;
            }
         }
      }
      for (int k = 0; k < n; k++)
      {
         for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < n; j++)
            {
               if (floyd[i][k] && floyd[k][j])
                  floyd[i][j] = 1;
            }
         }
      }
      int ans = 0;
      for (int i = 0; i < v.size(); i++)
      {
         if (!floyd[v[i].first][v[i].second])
            ans++;
      }
      printf("%d\n", ans);
   }
}