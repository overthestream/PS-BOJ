#include <iostream>
using namespace std;

int n, d[1001] = {0, 1, 2};

int main(void)
{
  cin >> n;
  for (int i = 3; i < n + 1; i++)
  {
    d[i] = d[i - 2] + d[i - 1];
    d[i] %= 10007;
  }
  cout << d[n] << "\n";
  return 0;
}