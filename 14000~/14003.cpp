#include <iostream>
#include <vector>

using namespace std;

int arr[1000010];
int bt[1000010];
int ans[1000010];

int bSearch(int lo, int hi, int num, int *lis)
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
  int lis[1000010];
  int index = 0;
  lis[index++] = arr[0];
  bt[0] = 0;

  for (int i = 1; i < len; ++i)
    if (arr[i] > lis[index - 1])
    {
      bt[i] = index;
      lis[index++] = arr[i];
    }
    else
    {
      int idx = bSearch(0, index - 1, arr[i], lis);
      lis[idx] = arr[i];
      bt[i] = idx;
    }

  return index;
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

  int idx = res - 1;
  int index = 0;
  for (int i = n - 1; i >= 0; --i)
    if (bt[i] == idx)
    {
      ans[index++] = arr[i];
      --idx;
    }

  for (int i = index - 1; i >= 0; --i)
    cout << ans[i] << " ";
}