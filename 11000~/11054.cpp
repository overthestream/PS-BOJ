#include <stdio.h>

int main(void)
{
  int N;
  scanf("%d", &N);

  int arr[1000];
  for (int i = 0; i < N; ++i)
    scanf("%d", arr + i);
  int arrR[1000];
  for (int i = 0; i < N; ++i)
    arrR[i] = arr[N - i - 1];

  int decDP[1000] = {
      0,
  };
  for (int i = 0; i < N; ++i)
  {
    decDP[i] = 1;
    for (int j = 0; j < i; ++j)
    {
      if (arrR[j] < arrR[i] && decDP[i] < decDP[j] + 1)
      {
        decDP[i] = decDP[j] + 1;
      }
    }
  }

  int incDP[1000] = {
      0,
  };
  for (int i = 0; i < N; ++i)
  {
    incDP[i] = 1;
    for (int j = 0; j < i; ++j)
    {
      if (arr[j] < arr[i] && incDP[i] < incDP[j] + 1)
      {
        incDP[i] = incDP[j] + 1;
      }
    }
  }

  int max = 0;
  for (int i = 0; i < N; ++i)
  {
    max = incDP[i] + decDP[N - i - 1] > max ? incDP[i] + decDP[N - i - 1] : max;
  }

  printf("%d", max - 1);
}