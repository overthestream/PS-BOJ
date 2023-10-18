#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int T, N, M;
  scanf("%d %d", &T, &N);

  int a[1005], b[1005];
  for (int i = 0; i < N; ++i)
    scanf("%d", a + i);

  scanf("%d", &M);
  for (int i = 0; i < M; ++i)
    scanf("%d", b + i);

  vector<int> aSub, bSub;

  for (int i = 0; i < N; ++i)
  {
    int sum = a[i];
    aSub.push_back(sum);
    for (int j = i + 1; j < N; ++j)
    {
      sum += a[j];
      aSub.push_back(sum);
    }
  }
  for (int i = 0; i < M; ++i)
  {
    int sum = b[i];
    bSub.push_back(sum);
    for (int j = i + 1; j < M; ++j)
    {
      sum += b[j];
      bSub.push_back(sum);
    }
  }
  sort(aSub.begin(), aSub.end());

  long long ans = 0;
  for (int i = 0; i < bSub.size(); ++i)
  {
    long long diff = T - bSub[i];

    auto ub = upper_bound(aSub.begin(), aSub.end(), diff);
    auto lb = lower_bound(aSub.begin(), aSub.end(), diff);
    ans += (ub - lb);
  }
  printf("%lld", ans);
}