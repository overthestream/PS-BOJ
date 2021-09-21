#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int V;
vector<pii> adj[100001];
bool visit[100001];

int maximum, leaf;

void DFS(int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> V;
  for (int i = 1; i <= V; ++i)
  {
    int node;
    cin >> node;
    int to, weight;
    cin >> to;
    while (to != -1)
    {
      cin >> weight;
      adj[node].push_back(make_pair(to, weight));
      cin >> to;
    }
  }
  DFS(1, 0);
  maximum = 0;
  for (int i = 1; i <= V; ++i)
    visit[i] = false;
  DFS(leaf, 0);
  cout << maximum;
}

void DFS(int node, int dist)
{
  visit[node] = true;
  if (dist > maximum)
  {
    maximum = dist;
    leaf = node;
  }
  for (int i = 0; i < adj[node].size(); ++i)
    if (!visit[adj[node][i].first])
      DFS(adj[node][i].first, dist + adj[node][i].second);
}