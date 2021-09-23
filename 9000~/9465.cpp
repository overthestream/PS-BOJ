#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  while (T--)
  {
    int val[100001][2] = {
        0,
    };
    int dp[100001][3] = {
        0,
    };
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> val[i][0];
    for (int i = 0; i < n; ++i)
      cin >> val[i][1];
    for (int i = 1; i <= n; ++i)
    {
      dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + val[i - 1][0];
      dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + val[i - 1][1];
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
  }
}