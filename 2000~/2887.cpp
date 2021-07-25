#include <cstdio>

#include <utility>
#include <algorithm>
#include <queue>

typedef struct
{
  int x;
  int y;
  int z;
} planet;

typedef struct
{
  int from;
  int to;
  int cost;
} edge;

using namespace std;

int parent[100001];

int find(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
  a = find(a);
  b = find(b);

  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;
}

struct cmp
{
  bool operator()(edge t, edge u)
  {
    return t.cost > u.cost;
  }
};
typedef pair<int, int> pii;

int main()
{
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    parent[i] = i;
  }
  pii xArr[N], yArr[N], zArr[N];

  for (int i = 0; i < N; ++i)
  {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    xArr[i] = pii(x, i);
    yArr[i] = pii(y, i);
    zArr[i] = pii(z, i);
  }

  sort(xArr, xArr + N);
  sort(yArr, yArr + N);
  sort(zArr, zArr + N);
  priority_queue<edge, vector<edge>, cmp> pq;
  for (int i = 0; i < N - 1; ++i)
  {
    edge x;
    x.from = xArr[i].second;
    x.to = xArr[i + 1].second;
    x.cost = xArr[i + 1].first - xArr[i].first;
    pq.push(x);

    edge y;
    y.from = yArr[i].second;
    y.to = yArr[i + 1].second;
    y.cost = yArr[i + 1].first - yArr[i].first;
    pq.push(y);

    edge z;
    z.from = zArr[i].second;
    z.to = zArr[i + 1].second;
    z.cost = zArr[i + 1].first - zArr[i].first;
    pq.push(z);
  }

  int cnt = 0, total = 0;

  while (cnt < N - 1)
  {
    edge cmp = pq.top();
    int from = cmp.from;
    int to = cmp.to;
    int cost = cmp.cost;

    if (find(from) != find(to))
    {
      unite(from, to);
      total += cost;
      cnt++;
    }
    pq.pop();
  }
  printf("%d", total);
}