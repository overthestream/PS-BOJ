/*
오늘 배울 것 . 
스위핑 알고리즘 
그냥 어떤 선이나 공간을 한쪽에서부터 싹 쓸어버리는 것인데,
한번만 전체 공간을 스캔하면서 마주치는 요소에 대해 뭔가를 해주면 정답이 구해진다.

예제- 2170 - 선긋기 : 골드 V
수평선 위에 선분을 여러 번 긋는데, 모든 선분을 긋고 난 후 선분이 덮인 구간 길이 총합을 구하는 문제.
좌표 범위가 20억이고 그러니까 뭐 20억짜리 배열을 만드는건 당연히 불가. 

이어졌거나 겹친 선분들을 아예 한 구간으로 합쳐서 마지막에 합쳐진 구간 길이만 세면 되지 않을까? 라는 발상.
시작점 기준으로 정렬을 한 뒤 시작해보자.

현재 구간을 이어 붙일 수 있는 한 최대로 이어붙인다. 

현재 선분의 끝점에 도달하기 전에 다른 선분이 시작되면 이어지는 것이므로 정렬을 하면 된다.

각 선분 정보를 저장한 뒤 정렬하고 순회하면서, 선분 번화와 현재 구간의 시작과 끝을 토대로 순회하면 될 것 같다.

*/

#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
const int INF = 1e9 + 1;
int main()
{
  int N;
  scanf("%d", &N);

  P L[1000000];
  for (int i = 0; i < N; i+)
  {
    int s, e;
    scanf("%d %d", &s, &e);
    L[i] = P(s, e);
  }
  sort(L, L + N);

  int result = 0, l = -INF, r = -INF;
  for (int i = 0; i < N; ++i)
  {
    if (r < L[i].first)
    {
      result += r - l;
      l = L[i].first;
      r = L[i].second;
    }
    else
      r = max(r, L[i].second);
  }
  result += r - l;
  printf("%d", result);
}