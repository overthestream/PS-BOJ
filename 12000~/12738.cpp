#include <iostream>
#include <vector>

using namespace std;

vector<int> lis;

int getPos(int num)
{
  int lo = 0, hi = lis.size() - 1;

  while (lo < hi)
  {
    int mid = (lo + hi) / 2;
    if (lis[mid] < num)
      lo = mid + 1;
    else
      hi = mid;
  }
  return hi;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, tmp;
  cin >> n >> tmp;
  lis.push_back(tmp);
  for (int i = 1; i < n; ++i)
  {
    cin >> tmp;
    if (tmp > lis.back())
      lis.push_back(tmp);
    else
      lis[getPos(tmp)] = tmp;
  }
  cout << lis.size();
}