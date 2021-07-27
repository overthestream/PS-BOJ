#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

int dist[1010];
using namespace std;

typedef pair<int, int> pii;

vector<pii> vec[100001];

void solve(int source)
{
  dist[source] = 0;

  priority_queue<pii> pq;
  pq.push(pii(dist[source], source));

  while (!pq.empty())
  {
    int cur = pq.top().second;
    int distance = pq.top().first * -1;
    pq.pop();
    if (dist[cur] < distance)
      continue;
    for (int i = 0; i < vec[cur].size(); ++i)
    {
      int next = vec[cur][i].first;
      int nextDist = distance + vec[cur][i].second;
      if (nextDist < dist[next])
      {
        dist[next] = nextDist;
        pq.push(pii(nextDist * -1, next));
      }
    }
  }
}

int main()
{
  int start, end;
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0; i <= N; ++i)
    dist[i] = 987654321;

  for (int i = 0; i < M; ++i)
  {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    vec[u].push_back(pii(v, w));
  }
  scanf("%d %d", &start, &end);
  solve(start);
  printf("%d", dist[end]);
}