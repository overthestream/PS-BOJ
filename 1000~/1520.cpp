#include <cstdio>
#include <string.h>

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
// dp[i][j] = i -> j 경로 수
int dp[505][505];
int heightMap[505][505];
int M, N;

int DFS(int i, int j)
{
  int result = 0;
  for (int k = 0; k < 4; ++k)
  {
    int ni = i + di[k], nj = j + dj[k];
    if (ni < 0 || ni >= M)
      continue;
    if (nj < 0 || nj >= N)
      continue;
    if (heightMap[ni][nj] > heightMap[i][j])
    {
      if (dp[ni][nj] == -1)
      {
        DFS(ni, nj);
      }
      result += dp[ni][nj];
    }
  }
  return dp[i][j] = result;
}

int main()
{
  scanf("%d %d", &M, &N);
  for (int i = 0; i < M; ++i)
    for (int j = 0; j < N; ++j)
      scanf("%d", &heightMap[i][j]);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 1;
  DFS(M - 1, N - 1);
  printf("%d", dp[M - 1][N - 1]);
}