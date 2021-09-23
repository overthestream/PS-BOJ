#include <iostream>
#include <vector>

using namespace std;

int n, m, wei, val, cnt, dp[10001], idx;
vector<int> w, v;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
  {
    cin >> wei >> val >> cnt;
    for (int j = 0; cnt > 0; ++j)
    {
      idx = min(1 << j, cnt);
      v.push_back(idx * val);
      w.push_back(idx * wei);
      cnt -= idx;
    }
  }
  for (int i = 0; i < w.size(); ++i)
    for (int j = m; j >= w[i]; --j)
      dp[j] = max(dp[j - w[i]] + v[i], dp[j]);

  cout << dp[m];
}
