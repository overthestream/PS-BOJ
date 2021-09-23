#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  int val[101];
  int dp[101][10001];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i)
  {
    cin >> val[i];
    dp[i][0] = 0;
  }
  for (int i = 1; i <= k; ++i)
    if (val[1] == 1)
      dp[1][i] = i;
    else
      dp[1][i] = i % val[1] == 0 ? i / val[1] : -1;
  for (int i = 2; i <= n; ++i)
  {
    for (int j = 1; j <= k; ++j)
    {
      if (j >= val[i])
        if (dp[i - 1][j] == -1)
        {
          dp[i][j] = dp[i][j - val[i]] == -1 ? -1 : dp[i][j - val[i]] + 1;
        }
        else if (dp[i][j - val[i]] == -1)
        {
          dp[i][j] = dp[i - 1][j];
        }
        else
          dp[i][j] = min(dp[i - 1][j], dp[i][j - val[i]] + 1);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[n][k];
}