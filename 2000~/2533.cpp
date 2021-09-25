#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

vector<int> adj[1000000], child[1000000];
bool visited[1000000];
int N, dp[1000000][2];

void dfs(int curr)
{
  visited[curr] = true;
  for (int next : adj[curr])
  {
    if (!visited[next])
    {
      child[curr].push_back(next);
      dfs(next);
    }
  }
}

int SNS(int curr, bool pe)
{
  int &ret = dp[curr][pe];
  if (ret != -1)
    return ret;

  int notpick = INF, pick = 1;
  for (int next : child[curr])
    pick += SNS(next, true);
  if (pe)
  {
    notpick = 0;
    for (int next : child[curr])
      notpick += SNS(next, false);
  }
  return ret = min(notpick, pick);
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N - 1; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);

  memset(dp, -1, sizeof(dp));
  printf("%d\n", SNS(0, true));
}
