#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M, dst;
vector<pii> adj[1001];
int dist[1001];
int maximum;

int dijkstra(int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> dst;
  for (int i = 0; i < M; ++i)
  {
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].push_back(make_pair(to, cost));
  }

  for (int i = 1; i <= N; ++i)
  {
    int res = dijkstra(i, dst);
    res += dijkstra(dst, i);
    maximum = max(maximum, res);
  }
  cout << maximum;
}

int dijkstra(int src, int dest)
{
  if (src == dest)
    return 0;
  for (int i = 1; i <= N; ++i)
    dist[i] = 98765432;
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
  return dist[dest];
}