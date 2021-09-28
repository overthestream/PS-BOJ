#include <iostream>
using namespace std;

const int MAX = 8e6 + 1;
long long x;

long long euler(long long n)
{
  long long pi = n, prime = 2;
  while (prime * prime <= n)
  {
    if (n % prime == 0)
      pi -= pi / prime;
    while (n % prime == 0)
      n /= prime;
    prime++;
  }
  if (n != 1)
    pi -= pi / n;
  return pi;
}

int main()
{
  cin >> x;
  cout << euler(x);
}