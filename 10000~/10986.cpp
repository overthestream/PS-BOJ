#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{

  int N, M;

  scanf("%d %d", &N, &M);

  int arr[1000000 + 2];
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", arr + i);
    arr[i] %= M;
  }
  /// prefixSum[i] = 0~i sum
  long long rem[1000 + 3];
  fill(rem, rem + 1003, 0);
  int prefixSum[1000000 + 2];
  long long solution = 0;
  prefixSum[0] = arr[0] % M;
  if (prefixSum[0] == 0)
    solution++;
  rem[prefixSum[0]]++;
  for (int i = 1; i < N; ++i)
  {
    prefixSum[i] = (prefixSum[i - 1] % M + arr[i] % M) % M;
    if (prefixSum[i] == 0)
      solution++;
    rem[prefixSum[i]]++;
  }

  for (int i = 0; i < M; ++i)
  {

    solution += rem[i] * (rem[i] - 1) / 2;
  }

  printf("%lld", solution);
}