#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef long long int ll;
int main(void)
{
  ll min, max;
  scanf("%lld %lld", &min, &max);
  ll square = 2;
  ll start;
  bool *isSquareNo = (bool *)malloc(sizeof(bool) * (max - min + 1)); // 0 = min
  memset(isSquareNo, 0, sizeof(isSquareNo));
  while (square * square <= max)
  {
    start = min / (square * square) * square * square + (min % (square * square) ? square * square : 0);
    for (ll i = 0; start + i * square * square <= max; ++i)
    {
      isSquareNo[start - min + i * square * square] = 1;
    }
    square++;
  }
  int count = 0;
  for (int i = 0; i < max - min + 1; ++i)
  {
    if (!isSquareNo[i])
      count++;
  }
  printf("%d", count);
  free(isSquareNo);
}