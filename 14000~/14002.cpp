#include <iostream>
#include <vector>

using namespace std;

int arr[1000];
vector<int> bt;

int bSearch(int lo, int hi, int num, vector<int> lis)
{
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

int getLISsize(int *arr, int len)
{
  vector<int> lis;
  lis.push_back(arr[0]);
  bt.push_back(0);
  int f = 0;
  for (int i = 1; i < len; ++i)
    if (arr[i] > lis.back())
    {
      bt.push_back(lis.size());
      lis.push_back(arr[i]);
    }
    else
    {
      int idx = bSearch(0, lis.size() - 1, arr[i], lis);
      lis[idx] = arr[i];
      bt.push_back(idx);
    }

  return lis.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, tmp;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int res = getLISsize(arr, n);
  cout << res << '\n';

  vector<int> ans;
  int idx = res - 1;

  for (int i = bt.size() - 1; i >= 0; --i)
    if (bt[i] == idx)
    {
      ans.push_back(arr[i]);
      --idx;
    }

  for (int i = ans.size() - 1; i >= 0; --i)
    cout << ans[i] << " ";
}