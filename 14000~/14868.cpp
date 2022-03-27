
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

bool pool[2010][2010];
int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
int day = 0, n, t;
pii civilization[100100];
bool isSecond = false;
bool visit[2010][2010] = {false};

int root[4000100];

queue<pii> melt;

bool isValid(int i, int j)
{
  return i >= 0 && i < n && j >= 0 && j < n;
}
int Find(int node)
{
  if (root[node] == node)
    return node;
  root[node] = Find(root[node]);
  return root[node];
}
void Union(int nodeA, int nodeB)
{
  if (nodeB < nodeA)
  {
    int temp = nodeA;
    nodeA = nodeB;
    nodeB = temp;
  }
  if (Find(nodeA) != Find(nodeB))
  {
    root[Find(nodeA)] = Find(nodeB);
  }
}
bool isSolved()
{
  int root = Find(civilization[0].first * n + civilization[0].second);
  for (int i = 1; i < t; ++i)
  {
    if (root != Find(civilization[i].first * n + civilization[i].second))
      return false;
  }
  return true;
}

void dayOff()
{
  queue<pii> next;
  while (!melt.empty())
  {
    pii cur = melt.front();
    melt.pop();
    int curI = cur.first;
    int curJ = cur.second;
    pool[curI][curJ] = 1;
    for (int i = 0; i < 4; ++i)
    {
      int ni = curI + di[i];
      int nj = curJ + dj[i];
      if (isValid(ni, nj) && (pool[ni][nj] == 1))
      {
        Union(curI * n + curJ, ni * n + nj);
      }
    }
    for (int i = 0; i < 4; ++i)
    {
      int ni = curI + di[i];
      int nj = curJ + dj[i];
      if (isValid(ni, nj) && pool[ni][nj] == 0 && !visit[ni][nj])
      {
        next.push(make_pair(ni, nj));
        visit[ni][nj] = true;
      }
    }
  }
  while (!next.empty())
  {
    pii tmp = next.front();
    int i = tmp.first;
    int j = tmp.second;
    next.pop();
    if (pool[i][j] == 0)
      melt.push(tmp);
  }
  ++day;
}

void input()
{

  scanf("%d %d ", &n, &t);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      root[i * n + j] = i * n + j;

  for (int i = 0; i < t; ++i)
  {
    int tmp1, tmp2;
    scanf("%d %d", &tmp1, &tmp2);

    civilization[i] = make_pair(tmp1 - 1, tmp2 - 1);
    pool[civilization[i].first][civilization[i].second] = 1;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
      if (pool[i][j] == 1)
      {
        int node = i * n + j;
        for (int k = 0; k < 4; ++k)
        {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (isValid(ni, nj) && (pool[ni][nj] == 1))
          {
            Union(node, ni * n + nj);
          }
        }
      }
      else
      {
        for (int k = 0; k < 4; ++k)
        {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (isValid(ni, nj) && (pool[ni][nj] == 1))
          {
            melt.push(make_pair(i, j));
            break;
          }
        }
      }
    }
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();

  while (!isSolved())
    dayOff();
  cout << day;

  return 0;
}
