#include <iostream>
#include <cmath>

using namespace std;

char star[6600][6600];

void print(int, int, int);

void space(int, int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  print(0, 0, n);

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      cout << star[i][j];
    cout << '\n';
  }
}

void print(int r, int c, int size)
{
  if (size == 3)
  {
    for (int i = r; i < r + 3; ++i)
      for (int j = c; j < c + 3; ++j)
        if (i == r + 1 && j == c + 1)
          star[i][j] = ' ';
        else
          star[i][j] = '*';
    return;
  }
  else
  {
    print(r, c, size / 3);
    print(r, c + size / 3, size / 3);
    print(r, c + 2 * size / 3, size / 3);
    print(r + size / 3, c, size / 3);
    space(r + size / 3, c + size / 3, size / 3);
    print(r + size / 3, c + 2 * size / 3, size / 3);
    print(r + 2 * size / 3, c, size / 3);
    print(r + 2 * size / 3, c + size / 3, size / 3);
    print(r + 2 * size / 3, c + 2 * size / 3, size / 3);
  }
}

void space(int r, int c, int size)
{
  for (int i = r; i < r + size; ++i)
    for (int j = c; j < c + size; ++j)
      star[i][j] = ' ';
}