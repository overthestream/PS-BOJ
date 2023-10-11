#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
struct Compare
{
  bool operator()(const pii &a, const pii &b)
  {
    return a.second > b.second;
  }
};

vector<int> solve(int N, int M, int K, int X, vector<pii> adjacList[])
{
  vector<int> result;
  vector<bool> visit(N + 5, false);
  vector<int> dist(N + 5, 50000000);
  priority_queue<pii, vector<pii>, Compare> pq;

  pq.push(make_pair(X, 0));
  dist[X] = 0;

  while (!pq.empty())
  {
    int curr;
    do
    {
      curr = pq.top().first;
      pq.pop();
    } while (!pq.empty() && visit[curr]);

    visit[curr] = true;
    vector<pii> currAdjList = adjacList[curr];
    for (int j = 0; j < currAdjList.size(); ++j)
    {
      int to = currAdjList[j].first;

      if (dist[curr] + 1 < dist[to])
      {
        dist[to] = dist[curr] + 1;
      }
      if (!visit[to])
        pq.push(make_pair(to, dist[to]));
    }
  }

  for (int i = 1; i <= N; ++i)
  {
    if (dist[i] == K)
      result.push_back(i);
  }

  return result;
}

void readInput(int &N, int &M, int &K, int &X, vector<pii> adjacList[])
{
  scanf("%d %d %d %d", &N, &M, &K, &X);
  for (int i = 0; i < M; ++i)
  {
    int u, v;
    scanf("%d %d", &u, &v);

    adjacList[u].push_back(make_pair(v, 1));
  }
}

void printOutput(vector<int> result)
{
  if (result.empty())
    printf("-1\n");
  else
  {
    for (int i = 0; i < result.size(); ++i)
    {
      printf("%d\n", result[i]);
    }
  }
}

int main()
{
  int N, M, K, X;
  vector<pii> adjacList[300004];

  readInput(N, M, K, X, adjacList);
  vector<int> result = solve(N, M, K, X, adjacList);
  printOutput(result);
}