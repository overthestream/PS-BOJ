#include <cstdio>
#include <iostream>
#define MAX 987654321

using namespace std;

bool temp[18][18], org[18][18];

int N;

int dy[] = {1, 0, 0, 0, -1};
int dx[] = {0, -1, 0, 1, 0};
int cnt, result = MAX;

void turn(int, int);
bool isDone();
bool isValid(int, int);
void solve();
void init();

int main()
{
  cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
      char tmp;
      scanf(" %c", &tmp);
      org[i][j] = tmp == '0';
    }
  solve();
}

void solve()
{
  for (int i = 0; i < 1 << N; ++i)
  {
    init();
    for (int x = 0; x < N; ++x)
      if (i & 1 << x)
        turn(0, x);
    for (int y = 1; y < N; ++y)
    {
      for (int x = 0; x < N; ++x)
      {
        if (!temp[y - 1][x])
          turn(y, x);
      }
    }
    if (isDone())
      result = min(result, cnt);
  }

  printf("%d", result == MAX ? -1 : result);
}

bool isValid(int y, int x)
{
  return (y >= 0 && y < N && x >= 0 && x < N);
}

bool isDone()
{
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (!temp[i][j])
        return false;
  return true;
}

void turn(int y, int x)
{
  ++cnt;
  for (int i = 0; i < 5; ++i)
  {
    int ydy = y + dy[i];
    int xdx = x + dx[i];
    if (isValid(ydy, xdx))
      temp[ydy][xdx] = !temp[ydy][xdx];
  }
}

void init()
{
  cnt = 0;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      temp[i][j] = org[i][j];
}