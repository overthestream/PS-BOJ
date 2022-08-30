#include <stdio.h>
#include <math.h>

int cubesssss[100]; // size
int cubennnn[100];  // # of cube

bool cant = false;

int solve(int l, int w, int h)
{
  if (l > 0 && w > 0 && h > 0)
  {
    int min = l;
    min = w < min ? w : min;
    min = h < min ? h : min;

    int min_s = floor(log2(min));

    do
    {
      if (!cubennnn[min_s])
        continue;
      cubennnn[min_s]--;
      int size = cubesssss[min_s];
      return solve(l - size, size, h) + solve(l, w - size, h) + solve(size, size, h - size) + 1;

    } while (--min_s >= 0);
    cant = true;
    return -1;
  }
  return 0;
}

int main()
{
  int l, w, h, n;
  scanf("%d %d %d%d", &l, &w, &h, &n);

  for (int i = 0, a, b; i < n + 1; i++)
  {

    scanf("%d %d", &a, &b);
    scanf("");
    cubesssss[i] = 1;
    for (int j = 0; j < a; ++j)
      cubesssss[i] *= 2;
    cubennnn[i] = b;

    if (i == n - 1)
      break;
  }

  int result = solve(l, w, h);
  printf("%d", cant ? -1 : result);
}
