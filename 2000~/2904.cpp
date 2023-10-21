#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
  int n, x;
  scanf("%d", &n);
  map<int, int> m[100];
  map<int, int> p;
  vector<int> pp;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    for (int j = 2; j * j <= x; j++)
    {
      if (x % j == 0)
      {
        int cnt = 0;
        for (; x % j == 0; x /= j)
          cnt++;
        m[i][j] = cnt;
        if (!p[j])
          pp.push_back(j);
        p[j] += cnt;
      }
    }
    if (x > 1)
    {
      m[i][x] = 1;
      if (!p[x])
        pp.push_back(x);
      p[x] += 1;
    }
  }
  int gcd = 1, ans = 0;
  for (int i = 0; i < pp.size(); i++)
  {
    int k = p[pp[i]] / n;
    int mul = 1;
    for (int j = 0; j < k; j++)
      mul *= pp[i];
    gcd *= mul;
    for (int j = 0; j < n; j++)
      if (m[j][pp[i]] < k)
        ans += k - m[j][pp[i]];
  }
  printf("%d %d", gcd, ans);
}