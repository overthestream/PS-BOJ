#include <iostream>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

typedef long long ll;

typedef struct
{
  ll first;
  ll second;
  ll val;
} pii;
typedef pair<ll, ll> pll;

pii points[3010];
pll leaf[5000];
ll segtree[5000];

ll init(ll nodeSegL, ll nodeSegR, ll curNode)
{
  if (nodeSegL == nodeSegR)
    return segtree[curNode] = leaf[nodeSegL].second;
  ll mid = (nodeSegL + nodeSegR) / 2;
  return segtree[curNode] = init(nodeSegL, mid, curNode * 2) + init(mid + 1, nodeSegR, curNode * 2 + 1);
}
ll getSum(int targetSegL, int targetSegR, int nodeSegL, int nodeSegR, int curNode)
{
  // node 구간과 구하려는 구간이 겹치지 않을 경우 0 반환
  if (targetSegL > nodeSegR || targetSegR < nodeSegL)
    return 0;
  // 구하려는 구간에 노드 구간이 완벽히 포함될 경우 해당 구간값 반환
  if (targetSegL <= nodeSegR && nodeSegR <= targetSegR)
    return segtree[curNode];
  // 일부만 포함될 경우,,, recursively 구함 (left, right child)
  int mid = (nodeSegL + nodeSegR) / 2;
  return getSum(targetSegL, targetSegR, nodeSegL, mid, curNode * 2) + getSum(targetSegL, targetSegR, mid + 1, nodeSegR, curNode * 2 + 1);
}

bool compare(pii a, pii b)
{
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

int main(void)
{
  ll max = -1;
  int N;
  scanf("%d ", &N);
  for (int i = 0; i < N; ++i)
    scanf("%lld %lld %lld", &points[i].first, &points[i].second, &points[i].val);

  // x좌표 오름차순 정렬: NlogN (N<3000)
  sort(&points[0], &points[N - 1], compare);

  // 좌표 압축: N
  int xMax, yMax;
  int prev = -1, idx = -1;
  // x좌표
  for (int i = 0; i < N; ++i)
  {
    if (prev == points[i].first)
      points[i].first = idx;
    else
    {
      prev = points[i].first;
      points[i].first = ++idx;
    }
    if (i == N - 1)
      xMax = idx;
  }
  // y좌표
  prev = -1, idx = -1;
  for (int i = 0; i < N; ++i)
  {
    if (prev == points[i].second)
      points[i].second = idx;
    else
    {
      prev = points[i].second;
      points[i].second = ++idx;
    }
    if (i == N - 1)
      yMax = idx;
  }
  xMax++;
  yMax++;
  // 각각의 x1 - x2 범위.. : N^2
  for (int i = 0; i < xMax; ++i)
  {
    for (int j = i; j < xMax; ++j)
    {
      // 별로 세그먼트 트리 구간합(y에 따른 구간합) : logN ==> N^2logN
      memset(leaf, 0, sizeof(leaf));
      memset(segtree, 0, sizeof(segtree));
      int idx = 0, k = -1;
      while (k++ < N)
      {
        if (points[k].first < i)
          continue;
        if (points[k].first > j)
          break;
        if (idx > 0 && (points[k].second == leaf[idx - 1].first))
        {
          leaf[idx - 1].second += points[k].val;
          continue;
        }
        leaf[idx].first = points[k].second;
        leaf[idx++].second = points[k].val;
      }
      sort(&leaf[0], &leaf[idx - 1]);
      init(0, idx - 1, 1);

      for (int q = 0; q < idx; ++q)
      {
        for (int w = q; w < idx; ++w)
        {
          ll ret = getSum(q, w, 0, idx - 1, 1);
          max = max < ret ? ret : max;
        }
      }
    }
  }
  printf("%lld", max);

  return 0;
}
