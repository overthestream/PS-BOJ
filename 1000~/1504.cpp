#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, E;
vector<pii> adj[1001];
int dist[1001];
int maximum;

int dijkstra(int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> E;
  for (int i = 0; i < E; ++i)
  {
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].push_back(make_pair(to, cost));
    adj[to].push_back(make_pair(from, cost));
  }
  int v1, v2;
  cin >> v1 >> v2;
  int result1;
  if ((result1 = dijkstra(1, v1)) != -1)
  {
    int tmp = dijkstra(v1, v2);
    if (tmp != -1)
    {
      result1 += tmp;
      int tmp = dijkstra(v2, N);
      if (tmp != -1)
        result1 += tmp;
      else
        result1 = -1;
    }
    else
      result1 = -1;
  }
  int result2;
  if ((result2 = dijkstra(1, v2)) != -1)
  {
    int tmp = dijkstra(v2, v1);
    if (tmp != -1)
    {
      result2 += tmp;
      int tmp = dijkstra(v1, N);
      if (tmp != -1)
        result2 += tmp;
      else
        result2 = -1;
    }
    else
      result2 = -1;
  }
  if (result1 != -1 && result2 != -1)
    cout << min(result1, result2);
  else
    cout << max(result1, result2);
}

int dijkstra(int src, int dest)
{
  if (src == dest)
    return 0;
  for (int i = 1; i <= N; ++i)
    dist[i] = 987654321;
  dist[src] = 0;
  bool visit[1001] = {
      false,
  };
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, src));
  while (!pq.empty())
  {
    int cur;
    do
    {
      cur = pq.top().second;
      pq.pop();
    } while (!pq.empty() && visit[cur]);
    if (visit[cur])
      break;
    visit[cur] = true;
    for (int i = 0; i < adj[cur].size(); ++i)
    {
      int next = adj[cur][i].first, cost = adj[cur][i].second;
      if (dist[next] > dist[cur] + cost)
      {
        dist[next] = dist[cur] + cost;
        pq.push(make_pair(dist[next], next));
      }
    }
  }
  return dist[dest] == 987654321 ? -1 : dist[dest];
}