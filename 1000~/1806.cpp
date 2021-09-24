#include <iostream>

using namespace std;

int arr[100000], res = 200000;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  int l = 0, r = 0, sub = 0;

  while (r <= n && l <= r && l < n)
    if (sub >= s)
    {
      res = min(res, r - l);
      sub -= arr[l++];
    }
    else
      sub += arr[r++];

  cout << ((res == 200000) ? 0 : res);
}