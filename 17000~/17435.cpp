#include <stdio.h>
#include <cmath>
int main(void)
{
  int m, Q;
  scanf("%d", &m);
  int sparseTable[(int)ceil(log2(500000)) + 1][m + 1]; // 앞에 거 : n = 2^i승
  for (int i = 1; i <= m; ++i)
  {
    scanf("%d", &sparseTable[0][i]);
  }
  for (int i = 1; i < (int)ceil(log2(500000)) + 1; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      sparseTable[i][j] = sparseTable[i - 1][sparseTable[i - 1][j]];
    }
  }

  scanf("%d", &Q);
  int n, x;
  for (int j = 0; j < Q; ++j)
  {
    int temp = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0; n >= (1 << i); ++i)
    {
      if (n & 1 << i)
      {
        if (!temp)
        {
          temp = sparseTable[i][x];
        }
        else
        {
          temp = sparseTable[i][temp];
        }
      }
    }
    printf("%d\n", temp);
  }
}