#include <iostream>
#include <queue>

using namespace std;

int arr[1000];

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
  for (int i = 1; i < len; ++i)
    if (arr[i] > lis.back())
      lis.push_back(arr[i]);
    else
      lis[bSearch(0, lis.size() - 1, arr[i], lis)] = arr[i];
  return lis.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  int n, from, to;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> from >> to;
    pq.push(make_pair(from, to));
  }
  int idx = 0;
  while (!pq.empty())
  {
    arr[idx++] = pq.top().second;
    pq.pop();
  }
  cout << n - getLISsize(arr, idx);
}