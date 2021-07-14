#include <stdio.h>

int min(int a, int b)
{
  return a > b ? b : a;
}

int recursive(int N, int W[][16], int cur, int status, int dp[][65536])
{
  if (dp[cur][status])
    return dp[cur][status];
  if (status == (1 << N) - 1)
  {
    if (W[cur][0])
      return W[cur][0];
    return 987654321;
  }
  dp[cur][status] = 987654321;
  for (int i = 0; i < N; ++i)
  {
    if (status & (1 << i) || W[cur][i] == 0)
      continue;
    dp[cur][status] = min(dp[cur][status], recursive(N, W, i, status | (1 << i), dp) + W[cur][i]);
  }
  return dp[cur][status];
}

void solve(int N, int W[][16])
{
  int dp[16][1 << 16] = {
      0,
  };

  printf("%d", recursive(N, W, 0, 1, dp));
}

int main()
{
  int N;
  scanf("%d", &N);
  int W[16][16];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      scanf("%d", &W[i][j]);
  solve(N, W);
}