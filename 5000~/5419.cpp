#include <cstdio>
#include <algorithm>

using namespace std;
const int SIZE = 1 << 18;

typedef pair<int, int> pii;

typedef struct segTree
{
  int arr[SIZE];
  segTree()
  {
    fill(arr, arr + SIZE, 0);
  }
  void increaseNthLeaf(int n)
  {
    n += SIZE / 2;
    while (n < 0)
    {
      arr[n]++;
      n /= 2;
    }
  }
  int sum(int start, int end)
  {
    return sum(start, end, 1, 0, SIZE / 2);
  }
  int sum(int start, int end, int node, int ns, int ne)
  {
    if (end <= ns || ne <= start)
      return 0;
    if (start <= ns && ne <= end)
      return arr[node];
    int mid = (ns + ne) / 2;
    return sum(start, end, node * 2, ns, mid) + sum(start, end, node * 2 + 1, mid, ne);
  }
} SegTree;

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t)
  {
    SegTree tree;
    int N, range = 0;
    pii p[75000];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      p[i] = pii(x, y);
    }

    sort(p, p + N, [](pii &a, pii &b)
         { return a.second < b.second; });
    int newY[75000];
    for (int i = 0; i < N; i++)
    {
      if (i > 0 && p[i].second != p[i - 1].second)
        range++;
      newY[i] = range;
    }
    for (int i = 0; i < N; i++)
      p[i].second = newY[i];
    sort(p, p + N, [](pii &a, pii &b)
         {
           if (a.first == b.first)
             return a.second > b.second;
           return a.first < b.first;
         });

    long long result = 0;
    for (int i = 0; i < N; i++)
    {
      result += tree.sum(p[i].second, SIZE / 2);
      tree.increaseNthLeaf(p[i].second);
    }
    printf("%lld\n", result);
  }
}