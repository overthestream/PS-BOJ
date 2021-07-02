#include <stdio.h>

int main(void)
{
  int N;
  scanf("%d", &N);

  int arr[1000];
  for (int i = 0; i < N; ++i)
    scanf("%d", arr + i);

  int dp[1000] = {
      0,
  };
  int max = 0;
  for (int i = 0; i < N; ++i)
  {
    dp[i] = 1;
    for (int j = 0; j < i; ++j)
    {
      if (arr[j] > arr[i] && dp[i] < dp[j] + 1)
      {
        dp[i] = dp[j] + 1;
      }
    }
    if (max < dp[i])
      max = dp[i];
  }
  printf("%d", max);
}