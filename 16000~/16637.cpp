#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int n, max_ans;
string str;

int cal(int a, int b, char oper)
{
  int result = a;
  switch (oper)
  {
  case '+':
    result += b;
    break;
  case '*':
    result *= b;
    break;
  case '-':
    result -= b;
    break;
  }
  return result;
}

void recur(int idx, int cur)
{
  // 1. 종료 조건
  if (idx > n - 1)
  {
    max_ans = max(max_ans, cur);
    return;
  }
  char oper = (idx == 0) ? '+' : str[idx - 1];

  // 2. 괄호로 묶는다 = 이전 + 괄호 계산
  if (idx + 2 < n)
  {
    int bracket = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
    recur(idx + 4, cal(cur, bracket, oper));
  }
  // 3. 안 묶는다 = 이전 + 다음
  recur(idx + 2, cal(cur, str[idx] - '0', oper));
}

int main()
{
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> str;

  max_ans = INT_MIN;
  recur(0, 0);
  cout << max_ans;
  return 0;
}
/*#include <stdio.h>

void compute(int *max, char *formula)
{
  int result = 0;

  int pos = 1;
  while(formula[pos]!=0){
    switch(formula[pos]{
      case '+': result += formula 
    })
  }

  if (result > *max)
    *max = result;
}

void DFS(char *formula, int pos, char* tmp, int* max)
{

  if(formula[pos] == 0){
    compute(max, tmp);
  }

}

int main(void)
{
  int max = 0b10000000000000000000000000000001;
  int N;
  char formula[20];
  scanf("%d", &N);
  scanf("%s", formula);
  DFS
  printf("%d", max);
}
*/