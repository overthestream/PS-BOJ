#include <stdio.h>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
pii segTree[1000000]; // maxVal, minVal pair segment tree
int num[100000];
int n, m;

pii init(int start, int end, int node)
{
   if (start == end)
   {
      if (num[start])
         return segTree[node] = make_pair(num[start], num[start]);
      else
      {
         return segTree[node] = make_pair(0, 1000000005);
      }
   }
   int mid = (start + end) / 2;
   pii left = init(start, mid, node * 2 + 1);
   pii right = init(mid + 1, end, node * 2 + 2);
   int minVal, maxVal;

   if (left.second)
   {
      if (right.second)
      {
         minVal = right.second < left.second ? right.second : left.second;
      }
      else
      {
         minVal = left.second;
      }
   }
   else
   {
      if (right.second)
      {
         minVal = right.second;
      }
      else
      {
         minVal = 0;
      }
   }

   maxVal = left.first > right.first ? left.first : right.first;

   return segTree[node] = make_pair(maxVal, minVal);
}

//ll sum(ll left, ll right, ll start, ll end, ll node)
//left, right는 값 구하는 구간, start, end는 node의 구간

pii getMinMax(int left, int right, int start, int end, int node) // left right : 구간 | start, end : tree index
{
   if (left > end || right < start)
      return make_pair(0, 1000000005);
   if (left <= start && end <= right)
      return segTree[node];
   int mid = (start + end) / 2;

   pii leftChild = getMinMax(left, right, start, mid, node * 2 + 1);
   pii rightChild = getMinMax(left, right, mid + 1, end, node * 2 + 2);
   return make_pair(leftChild.first > rightChild.first ? leftChild.first : rightChild.first, leftChild.second > rightChild.second ? rightChild.second : leftChild.second);
}

int main(void)
{

   scanf("%d %d", &n, &m);

   for (int i = 0; i < n; ++i)
      scanf("%d", num + i);

   init(0, n - 1, 0);

   for (int i = 0; i < m; ++i)
   {
      int a, b;
      pii p;
      scanf("%d %d", &a, &b);
      p = getMinMax(a - 1, b - 1, 0, n - 1, 0);
      printf("%d %d\n", p.second, p.first);
   }
}