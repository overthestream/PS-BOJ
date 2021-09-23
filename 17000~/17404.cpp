#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void)
{
  int N;
  scanf("%d", &N);
  int value[1001][3];
  for (int i = 1; i <= N; i++)
    for (int j = 0; j < 3; j++)
      scanf("%d", &value[i][j]);
  int dp[1001][3];
  int res = 987654321;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; ++j)
      if (i == j)
        dp[1][j] = value[1][j];
      else
        dp[1][j] = 987654321;
    for (int j = 2; j <= N; ++j)
    {
      dp[j][2] = value[j][2] + min(dp[j - 1][1], dp[j - 1][0]);
      dp[j][0] = value[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
      dp[j][1] = value[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
    }
    for (int j = 0; j < 3; ++j)
      if (i != j)
        res = min(res, dp[N][j]);
  }
  printf("%d", res);
  return 0;
}