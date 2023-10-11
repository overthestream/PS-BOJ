#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
int main()
{
  int V, E;
  vector<pii> adj[402];
  scanf("%d %d", &V, &E);

  int dist[402][402];
  for (int i = 0; i < 402; ++i)
    for (int j = 0; j < 402; ++j)
      dist[i][j] = 2147380000;
  for (int _ = 0; _ < E; ++_)
  {
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    dist[from][to] = cost;
  }

  for (int i = 1; i <= V; i++)
  {
    for (int j = 1; j <= V; ++j)
    {
      for (int k = 1; k <= V; ++k)
      {
        if (dist[j][i] != 2147380000 && dist[i][k] != 2147380000)
          dist[j][k] = dist[j][k] > dist[j][i] + dist[i][k] ? dist[j][i] + dist[i][k] : dist[j][k];
      }
    }
  }

  int min = 2147380000;
  for (int i = 1; i <= V; i++)
  {
    min = min > dist[i][i] ? dist[i][i] : min;
  }
  printf("%d", min == 2147380000 ? -1 : min);
}