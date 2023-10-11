#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
int main()
{
  int TC;
  scanf("%d", &TC);
  while (TC--)
  {
    int N, M, W;
    scanf("%d %d %d", &N, &M, &W);

    vector<pii> adj[505];
    vector<int> warms;
    for (int _ = 0; _ < M; ++_)
    {
      int S, E, T;
      scanf("%d %d %d", &S, &E, &T);
      adj[S].push_back(make_pair(E, T));
      adj[E].push_back(make_pair(S, T));
    }
    for (int _ = 0; _ < W; ++_)
    {
      int S, E, T;
      scanf("%d %d %d", &S, &E, &T);
      adj[S].push_back(make_pair(E, -T));
      warms.push_back(S);
    }
    bool cycle = false;
    for (int _ = 0; _ <= warms.size(); ++_)
    {
      int start = warms[_];
      int dist[505];
      for (int i = 1; i <= N; ++i)
        dist[i] = 2147483647;

      dist[start] = 0;

      for (int i = 0; i < N; ++i)
      {
        for (int j = 1; j <= N; ++j)
        {
          for (int k = 0; k < adj[j].size(); ++k)
          {
            int to = adj[j][k].first;
            int d = adj[j][k].second;

            if (dist[j] != 2147483647 && dist[to] > dist[j] + d)
            {
              dist[to] = dist[j] + d;
              if (i == N - 1)
              {
                cycle = true;
              }
            }
          }
        }
      }
      if (cycle)
        break;
    }
    if (cycle)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
}