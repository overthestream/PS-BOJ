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

int c[402][402] = {0};
int f[402][402] = {0};
vector<int> adj[402];

int main()
{

  int N, M;
  int total = 0, S = 0, T = 401; // 소 노드 1~ 200 축사 노드 201~ 400
  scanf("%d %d", &N, &M);

  // init
  for (int i = 1; i <= N; i++)
  {
    c[S][i] = 1;
    adj[S].push_back(i);
    adj[i].push_back(S);
  }
  for (int i = 201; i <= 200 + M; i++)
  {
    c[i][T] = 1;
    adj[i].push_back(T);
    adj[T].push_back(i);
  }

  for (int i = 1; i <= N; i++)
  {
    int K;
    scanf("%d", &K);
    for (int j = 0; j < K; j++)
    {
      int cow;
      scanf("%d", &cow);
      c[i][cow + 200]++;
      adj[i].push_back(cow + 200);
      adj[cow + 200].push_back(i);
    }
  }

  while (1)
  {

    int prev[402];
    fill(prev, prev + 402, -1);
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