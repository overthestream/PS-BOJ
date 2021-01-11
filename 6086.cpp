//노정훈 고컴 과탑먹자 ^!^

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

int main()
{

  int E;
  int c[52][52] = {0};
  int f[52][52] = {0};
  vector<int> adj[52];

  scanf("%d", &E);
  for (int i = 0; i < E; i++)
  {
    char u, v;
    int w;
    scanf(" %c %c %d", &u, &v, &w);
    if (u <= 'Z')
      u = u - 'A';
    else
      u = u - 'a' + 26;
    if (v <= 'Z')
      v = v - 'A';
    else
      v = v - 'a' + 26;

    c[u][v] = c[v][u] += w;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int total = 0, S = 'A' - 'A', T = 'Z' - 'A';

  while (1)
  {

    int prev[52];
    fill(prev, prev + 52, -1);
    queue<int> Q;
    Q.push(S);

    while (!Q.empty() && prev[T] == -1)
    {

      int cur = Q.front();
      Q.pop();
      for (int next : adj[cur])
      {
        if (c[cur][next] > f[cur][next] && prev[next] == -1)
        {
          Q.push(next);
          prev[next] = cur;
          if (next == T)
            break;
        }
      }
    }
    if (prev[T] == -1)
      break;

    int flow = 9876543210;
    for (int i = T; i != S; i = prev[i])
      flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

    for (int i = T; i != S; i = prev[i])
    {
      f[prev[i]][i] += flow;
      f[i][prev[i]] -= flow;
    }
    total += flow;
  }
  printf("%d", total);
  return 0;
}