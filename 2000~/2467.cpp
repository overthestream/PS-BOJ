#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  int N;
  scanf("%d", &N);
  long long arr[100000];
  for (int _ = 0; _ < N; _++)
  {

    scanf("%lld", arr + _);
  }

  int s = 0, e = N - 1;
  long long first = arr[s], second = arr[e];
  long long diff = abs(first + second);

  while (s < e)
  {
    long long f = arr[s], sec = arr[e];
    long long d = abs(f + sec);
    if (diff > d)
      first = f, second = sec, diff = d;

    if (f + sec < 0)
    {
      s++;
    }
    else if (f + sec > 0)
    {
      e--;
    }
    else
    {
      break;
    }
  }
  printf("%lld %lld", first, second);
}