#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#include <stdio.h>
#include <stdbool.h>

int check[16], n;
bool isPossible(int depth, int col)
{
  for (int i = 0; i < depth; i++)
  {
    if (col == check[i])
      return false;
    if (col == check[i] - depth + i)
      return false;
    if (col == check[i] + depth - i)
      return false;
  }
  return true;
}
long long queen(int depth)
{
  if (depth == n)
    return 1;
  long long result = 0;
  for (int i = 0; i < n; i++)
  {
    check[depth] = i;
    if (isPossible(depth, i))
      result += queen(depth + 1);
  }
  return result;
}

int main(void)
{

  scanf("%d", &n);
  printf("%lld", queen(0));

  return 0;
}