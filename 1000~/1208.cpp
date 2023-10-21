
#include <cstdio>
#include <map>
using namespace std;

int N, S, A[40], threshold, sum;
long long result;
map<int, int> cnt;

void dfs1(int pos)
{
  if (pos == threshold)
  {
    auto iter = cnt.find(sum);
    if (iter != cnt.end())
      ++iter->second;
    else
      cnt[sum] = 1;
    return;
  }
  dfs1(pos + 1);
  sum += A[pos];
  dfs1(pos + 1);
  sum -= A[pos];
}

void dfs2(int pos)
{
  if (pos == N)
  {

    auto iter = cnt.find(S - sum);
    if (iter != cnt.end())
      result += iter->second;
    return;
  }
  dfs2(pos + 1);
  sum += A[pos];
  dfs2(pos + 1);
  sum -= A[pos];
}

int main()
{
  scanf("%d %d", &N, &S);
  for (int i = 0; i < N; ++i)
    scanf("%d", A + i);
  threshold = N / 2;
  dfs1(0);
  dfs2(threshold);
  if (S == 0)
    --result;
  printf("%lld\n", result);
}
