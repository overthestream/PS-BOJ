#include <cstdio>
#include <utility>
int parseInt(int n, char *str)
{
  int tmp = n;
  int idx = 0;
  while (tmp)
  {
    str[idx++] = tmp % 10;
    tmp /= 10;
  }
  return idx;
}
bool isPalindrom(char *str, int size)
{
  for (int i = 0; i < size; ++i)
  {
    if (str[i] != str[size - i - 1])
      return false;
  }
  return true;
}

int main()
{
  while (1)
  {
    int tmp;
    scanf("%d", &tmp);
    if (!tmp)
      break;
    char str[6];
    memset(str, 0, sizeof(str));
    int size = parseInt(tmp, str);
    if (isPalindrom(str, size))
      printf("yes\n");
    else
      printf("no\n");
  }
}