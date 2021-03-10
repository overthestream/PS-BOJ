//노정훈 고컴 과탑먹자 ^!^

//아스키코드 A~Z 65-90 a~z 97-122 0~9 48-57
//10진수 입출력 %d(long =%ld longlong =%lld ) unsigned온리 양수(정수만) %u
//16진수 %X or %x(알파벳 대소)  8진수 %o /16진수 0x ~~ 8진수 0~~ ->%#X %#o
//char='문자'->아스키코드 %c 주의 : \n도 입력 됨.->" %c"사용 /문자열 %s (string)출력가능/입력시 &불필요 끝에는 구분 위한 \0 (null) ->2차원 배열도 가능. 자동으로 다음배열까지 .
//<\> 이스케이프 시퀀스    / 형변환 (자료형) / 입력시 &변수명
//실수입력%lf /실수출력%f long double %Lf /%e or %E -> e사용 %g or %G -> 소수점 따라 e or 0.xxxx /%a =p표기(16진법+2진법) ex 0x1.01p+6=(1+0*16^-1+1*16^-2)*2^6
//%(-)숫자 알파벳 -> 정렬해서 출력
//소수점 정밀도 : %(자리수).(정밀도)(서식)
//제곱 pow(밑,지수)

//포인터 = 메모리 주소 저장  자료형* &변수명(ex int* pnum= &num/ *ptr == num  true)  초기화시 NULL 사용
//%p로 출력 배열 명 = 상수형 포인터-> [0] 가리킴 = *arr=arr[0] 포인터 n 증감 = n* sizeof(type) 만큼 증감 -> 배열 접근 가능.
//arr[i]=*(arr+i) arr= 배열명 or 포인터 변수명
//포인터를 이용한 문자열 선언 ex) char* str = "String" == 임의의 메모리 공간에 "String" 저장, S의 메모라 공간을 str이 가리킴. 이후 str="~"로 변경가능
//printf("String")도 같은 논리. "String"을 임의의 메모리 공간에 저장 후 그 주소에 접근해 문자열 출력 ==printf(0x1234)
//포인터 배열 int* arr[n] -> *arr[n]으로 활용 가능 -> char* arr[n]으로 (char 포인터 배열, 문자열 이름 느낌)"문자열" 배열 사용 가능. printf와 같은 논리
// 배열을 함수의 인자로 전달하려면 ?? 포인터를 사용한다-> 값 변경도 가능 (Call by reference) 더블포인터 -> 포인터 값 변경 이처럼 *단항연산자는 무제한 중복 o
// 배열의 길이? sizeof(배열명)/sizeof(자료형)  가로행 세로열 배열[열][행]
//2차원 배열의 포인터 int (*ptr) [행] 선언 =배열포인터변수
//함수도 비슷. 함수 명= 함수 포인터 /선언: 반환형 (*ptr) (매개변수,매개변수 ...) -> ptr로도 함수 호출 O

//ex) scanf("%d",&num) == EOF = 입력값 X / 1: 입력 수, num에 수 저장 / 0: 입력 수 X

//공백포함 문자열 입력 : fgets(arr,sizeof(arr),stdin) (null 추가해야 함) /문자열 길이(null 제외) : strlen(str명) -unsigned int 형 /문자열 카피 strcpy(String,"~~~")
//구조체 : 변수를 묶어 새로운 자료형 만듦 /구조체 선언 struct 이름{자료형 이름 ~~~}/구조체 변수 선언 : struct type_name val_name
//구조체 멤버 접근 : 구조체 변수명.구조체 멤버명 / 구조체 배열 struct point arr[n] / 구조체 포인터 struct 이름* ptr=&이름 ->*ptr.구조체 멤버명 == ptr->구조체 멤버명
//구조체 변수 주소 = 구조체 첫 멤버 주소 -> 구조체명 = &구조체첫멤버
//typedef -> 자료형에 새 이름 부여 typedef type_name new_name -> 구조체 선언과 엮어[ typedef struct 구조체명(쌩략 O){멤버} 새 이름 ] -> 구조체 변수 선언시 struct 구조체명== 새 이름
//공용체: struct 대신 union : 멤버들이 하나의 메모리 공간 공유
//열거형 : enum 열거형 명{(상수)ex> Do=1, Re=2};-> 열거형명=Do==1;

//깨달음.. 2차원배열 = 배열의 배열
//실수 자료형은 %연산 X
//malloc은 자료형만큼의 바이트를 할당하고, 그 주소를 반환

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n, length[510][510] = {
           0,
},
       days[510][510] = {
           0,
};
int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}};
int solve(int i, int j)
{
  int max = 0, nextI, nextJ;
  bool isFound = false;
  if (days[i][j])
    return days[i][j];
  for (int k = 0; k < 4; k++)
  {
    nextI = i + dir[k][0];
    nextJ = j + dir[k][1];
    if (nextI >= n || nextI < 0 || nextJ >= n || nextJ < 0)
      continue;
    if (length[nextI][nextJ] < length[i][j])
    {
      isFound = true;
      if (max < solve(nextI, nextJ))
        max = solve(nextI, nextJ);
    }
  }
  if (!isFound)
    return days[i][j] = 1;
  else
    return days[i][j] = max + 1;
}

int main()
{

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &length[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      days[i][j] = solve(i, j);
  int max = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (max < days[i][j])
        max = days[i][j];
  printf("%d", max);
  return 0;
}