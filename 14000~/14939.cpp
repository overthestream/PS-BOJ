
#include <cstdio>
#include <iostream>
#define MAX 987654321

using namespace std;

bool temp[10][10], org[10][10];

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
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
    {
      char tmp;
      scanf(" %c", &tmp);
      org[i][j] = tmp == '#';
    }
  solve();
}

void solve()
{
  for (int i = 0; i < 1 << 10; ++i)
  {
    init();
    for (int x = 0; x < 10; ++x)
      if (i & 1 << x)
        turn(0, x);
    for (int y = 1; y < 10; ++y)
    {
      for (int x = 0; x < 10; ++x)
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
  return (y >= 0 && y < 10 && x >= 0 && x < 10);
}

bool isDone()
{
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
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
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      temp[i][j] = org[i][j];
}