#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int arr[500010];
int bt[500010];
stack<int> ans;

typedef pair<int, int> pii;

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
  int lis[500010];
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

  int n;
  cin >> n;

  pii arr[500001];
  for (int i = 0; i < n; ++i)
  {
    int a, b;
    cin >> a >> b;
    arr[i] = (make_pair(a, b));
  }

  sort(arr, arr + n);

  int sorted[500001];
  for (int i = 0; i < n; ++i)
    sorted[i] = arr[i].second;

  int res = getLISsize(sorted, n);
  cout << n - res << '\n';

  int idx = res - 1;
  int index = 0;
  for (int i = n - 1; i >= 0; --i)
    if (bt[i] == idx)
    {
      ans.push(sorted[i]);
      --idx;
    }

  int i = 0;
  while (!ans.empty())
  {
    if (arr[i].second == ans.top())
      ans.pop();
    else
      cout << arr[i].first << '\n';
    ++i;
  }
  for (i; i < n; ++i)
    cout << arr[i].first << '\n';
}