//노정훈 고컴 과탑먹자 ^!^

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>

typedef long long int ll;
using namespace std;

ll segTree[3000010];

ll leaf[1000010];

ll init(ll start, ll end, ll node)
{
   if (start == end)
      return segTree[node] = leaf[start];
   ll mid = (start + end) / 2;
   return segTree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(ll left, ll right, ll start, ll end, ll node)
{ //left, right는 값 구하는 구간, start, end는 node의 구간
   if (left > end || right < start)
      return 0;
   if (left <= start && end <= right)
      return segTree[node];
   ll mid = (start + end) / 2;
   return sum(left, right, start, mid, node * 2) + sum(left, right, mid + 1, end, node * 2 + 1);
}

void update(ll start, ll end, ll node, ll index, ll dif)
{ //index번째 수를 dif만큼 변경 / 내려가면서 부모의 구간합도 변경해주기

   if (start > index || end < index)
      return;
   segTree[node] += dif;
   if (start == end)
      return;
   ll mid = (start + end) / 2;
   update(start, mid, node * 2, index, dif);
   update(mid + 1, end, node * 2 + 1, index, dif);
}
int main()
{

   int N, M, K;
   scanf("%d %d %d", &N, &M, &K);
   for (int i = 0; i < N; i++)
      scanf("%d", leaf + i);
   init(0, N - 1, 1);
   ll order, a, b;
   for (int k = 0; k < M + K; k++)
   {
      scanf("%lld", &order);
      scanf("%lld %lld", &a, &b);

      if (order == 1)
      {
         update(0, N - 1, 1, a - 1, b - leaf[a - 1]);
         leaf[a - 1] = b;
      }
      else
      {
         printf("%lld\n", sum(a - 1, b - 1, 0, N - 1, 1));
      }
   }

   return 0;
}