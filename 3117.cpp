#include <stdio.h>
#include <cmath>
int main(void)
{
  int N, K, M;
  scanf("%d %d %d", &N, &K, &M);
  M--;
  int sparseTable[(int)ceil(log2(M)) + 1][K + 1]; // 앞에 거 : n = 2^i승
  int student[N + 1];

  for (int i = 1; i <= N; ++i)
  {
    scanf("%d", &student[i]);
  }
  for (int i = 1; i <= K; ++i)
  {
    scanf("%d", &sparseTable[0][i]);
  }

  for (int i = 1; i < (int)ceil(log2(M)) + 1; ++i)
  {
    for (int j = 1; j <= K; ++j)
    {
      sparseTable[i][j] = sparseTable[i - 1][sparseTable[i - 1][j]];
    }
  }

  for (int j = 1; j <= N; ++j)
  {
    int temp = student[j];
    // if M= 1 이면 f_1, sparseTable[0]
    for (int i = 0; M >= (1 << i); ++i)
    {
      if (M & 1 << i)
      {
        temp = sparseTable[i][temp];
      }
    }
    printf("%d ", temp);
  }
}