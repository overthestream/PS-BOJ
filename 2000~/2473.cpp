#include <algorithm>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  vector<int> arr;

  for (int i = 0; i < N; ++i)
  {
    int tmp;
    scanf("%d", &tmp);
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());

  int sol[3];

  int tmp[3];
  long long max = 3000000000;
  for (int i = 0; i < arr.size(); ++i)
  {
    tmp[0] = arr[i];

    int s = 0;
    int e = arr.size() - 1;
    long long tmpMax = 3000000000;
    if (i == s)
      s++;
    if (i == e)
      e--;
    while (s < e)
    {

      long long sum = arr[s] + arr[e];
      if (abs(sum + tmp[0]) < tmpMax)
      {
        tmp[1] = arr[s];
        tmp[2] = arr[e];

        tmpMax = abs(sum + tmp[0]);
      }
      if (sum < -tmp[0])
      {
        s++;
        if (s == i)
          s++;
      }
      else if (sum > -tmp[0])
      {
        e--;
        if (e == i)
          e--;
      }
      else
      {
        tmpMax = 0;

        tmp[0] = arr[i];
        tmp[1] = arr[s];
        tmp[2] = arr[e];
        break;
      }
    }
    if (tmpMax < max)
    {
      max = tmpMax;
      for (int j = 0; j < 3; ++j)
        sol[j] = tmp[j];
    }
  }
  vector<int> solution;
  for (int i = 0; i < 3; ++i)
    solution.push_back(sol[i]);
  sort(solution.begin(), solution.end());
  for (int i = 0; i < 3; ++i)
    printf("%d ", solution[i]);
}