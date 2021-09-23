#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  int val[101] = {
      0,
  };
  int dp[10001] = {
      1,
  };
  for (int i = 1; i <= n; ++i)
  {
    cin >> val[i];
  }
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= k; ++j)
    {
      if (j >= val[i])
        dp[j] += dp[j - val[i]];
    }
  }
  cout << dp[k];
}