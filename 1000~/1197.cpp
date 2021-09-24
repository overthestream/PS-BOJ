#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
  int v, e, m;
  Data(int ve, int end, int money)
  {
    v = ve;
    e = end;
    m = money;
  }
  bool operator<(Data &d)
  {
    return m < d.m;
  }
};

int res;
int arr[10001];

int Find(int v)
{
  if (v == arr[v])
    return v;
  else
    return arr[v] = Find(arr[v]);
}

void Union(int a, int b, int c)
{
  a = Find(a);
  b = Find(b);
  if (a != b)
  {
    arr[a] = b;
    res += c;
  }
}

int main()
{
  int V, E;
  cin >> V >> E;
  for (int i = 1; i <= V; i++)
  {
    arr[i] = i;
  }
  vector<Data> a;
  for (int i = 0; i < E; i++)
  {
    int e, b, c;
    cin >> e >> b >> c;
    a.push_back(Data(e, b, c));
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++)
  {
    Union(a[i].v, a[i].e, a[i].m);
  }
  cout << res << "\n";

  return 0;
}