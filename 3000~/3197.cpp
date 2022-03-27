
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

char pool[1510][1510];
int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
int day = 0, r, c;
pii first, second;
bool isSecond = false;

int root[2250100];

queue<pii> melt;

bool isValid(int i, int j)
{
  return i >= 0 && i < r && j >= 0 && j < c;
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
  return Find(first.first * c + first.second) == Find(second.first * c + second.second);
}

void dayOff()
{
  queue<pii> next;
  bool visit[1500][1500] = {false};
  while (!melt.empty())
  {
    pii cur = melt.front();
    melt.pop();
    int curI = cur.first;
    int curJ = cur.second;
    pool[curI][curJ] = '.';
    for (int i = 0; i < 4; ++i)
    {
      int ni = curI + di[i];
      int nj = curJ + dj[i];
      if (isValid(ni, nj) && (pool[ni][nj] == '.' || pool[ni][nj] == 'L'))
      {
        Union(curI * c + curJ, ni * c + nj);
      }
    }
    for (int i = 0; i < 4; ++i)
    {
      int ni = curI + di[i];
      int nj = curJ + dj[i];
      if (isValid(ni, nj) && pool[ni][nj] == 'X' && !visit[ni][nj])
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
    if (pool[i][j] == 'X')
      melt.push(tmp);
  }
  ++day;
}

void input()
{

  scanf("%d %d ", &r, &c);

  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      root[i * c + j] = i * c + j;

  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
    {
      scanf(" %c", &pool[i][j]);
      if (pool[i][j] == 'L')
        if (isSecond)
          second = make_pair(i, j);
        else
        {
          first = make_pair(i, j);
          isSecond = true;
        }
    }
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
    {
      if (pool[i][j] == '.' || pool[i][j] == 'L')
      {
        int node = i * c + j;
        for (int k = 0; k < 4; ++k)
        {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (isValid(ni, nj) && (pool[ni][nj] == '.' || pool[ni][nj] == 'L'))
          {
            Union(node, ni * c + nj);
          }
        }
      }
      else
      {
        for (int k = 0; k < 4; ++k)
        {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (isValid(ni, nj) && (pool[ni][nj] == '.' || pool[ni][nj] == 'L'))
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
