#include <cstdio>
#include <string.h>
#define MOD % 1000000000

int main()
{
  int N;
  scanf("%d", &N);

  // 자릿수, 최소수, 최대 수, 끝 수
  int dp[103][10][10][10];

  memset(dp, 0, sizeof(dp));

  for (int j = 1; j <= 9; ++j)
    dp[1][j][j][j] = 1;

  for (int i = 2; i <= N; ++i)
  {
    for (int k = 0; k <= 9; ++k)
    {
      for (int j = k; j <= 9; ++j)
      {
        if (k > 0)
        {
          dp[i][k - 1][j][k - 1] = (dp[i - 1][k][j][k] MOD + dp[i - 1][k - 1][j][k] MOD) MOD;
        }
        if (j < 9)
        {
          dp[i][k][j + 1][j + 1] = (dp[i - 1][k][j][j] MOD + dp[i - 1][k][j + 1][j] MOD) MOD;
        }
        for (int m = k + 1; m < j; ++m)
        {
          dp[i][k][j][m] = (dp[i - 1][k][j][m - 1] MOD + dp[i - 1][k][j][m + 1] MOD) MOD;
        }
      }
    }
  }

  int sol = 0;
  for (int i = 0; i <= 9; ++i)
  {
    sol += dp[N][0][9][i] MOD;
    sol = sol MOD;
  }
  printf("%d", sol);
}