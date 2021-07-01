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
    dp[i] = arr[i];
    for (int j = 0; j < i; ++j)
    {
      if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
      {
        dp[i] = dp[j] + arr[i];
      }
    }
    if (max < dp[i])
      max = dp[i];
  }
  printf("%d", max);
}