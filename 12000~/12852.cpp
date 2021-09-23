#include <string>
#include <vector>
#include <iostream>
using namespace std;
int d[1000002];
int pre[1000002];
int N;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  d[1] = 0;
  pre[1] = 0;
  for (int i = 2; i <= N; i++)
  {
    d[i] = d[i - 1] + 1;
    pre[i] = i - 1;
    if (i % 3 == 0 and d[i / 3] + 1 < d[i])
    {
      d[i] = d[i / 3] + 1;
      pre[i] = i / 3;
    }
    if (i % 2 == 0 and d[i / 2] + 1 < d[i])
    {
      d[i] = d[i / 2] + 1;
      pre[i] = i / 2;
    }
  }
  cout << d[N] << '\n';
  while (true)
  {
    cout << N << ' ';
    N = pre[N];
    if (N == 0)
      break;
  }
  return 0;
}