#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<pii> adj[1001];
int dist[1001];
int bt[1001];
int from, to;

int dijkstra(int, int);
void backtracking();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; ++i)
  {
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].push_back(make_pair(to, cost));
  }

  cin >> from >> to;
  cout << dijkstra(from, to) << endl;
  bt[from] = from;
  backtracking();
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
        bt[next] = cur;
      }
    }
  }
  return dist[dest];
}

void backtracking()
{
  int cnt = 1;
  stack<int> cities;
  int cur = to;
  while (cur != from)
  {
    cnt++;
    cities.push(cur);
    cur = bt[cur];
  }
  cities.push(from);

  cout << cnt << endl;
  while (!cities.empty())
  {
    cout << cities.top() << " ";
    cities.pop();
  }
}