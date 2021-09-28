#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix operator*(const matrix &a, const matrix &b)
{
  ll size = a.size();
  matrix res(size, vector<ll>(size));
  for (ll i = 0; i < size; i++)
  {
    for (ll j = 0; j < size; j++)
    {
      for (ll k = 0; k < size; k++)
      {
        res[i][j] += (a[i][k] % 1000000007) * (b[k][j] % 1000000007);
      }
      res[i][j] %= 1000000007;
    }
  }
  return res;
}

matrix power(matrix a, ll n)
{
  ll size = a.size();
  matrix res(size, vector<ll>(size));
  for (ll i = 0; i < size; i++)
  {
    res[i][i] = 1;
  }
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      res = res * a;
    }
    n /= 2;
    a = a * a;
  }
  return res;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;

  matrix a(2, vector<ll>(2));
  for (ll i = 0; i < 2; i++)
    for (ll j = 0; j < 2; j++)
      a[i][j] = !(i && j);

  if (n % 2)
    cout << (power(a, n)[0][1] - 1 + 1000000007) % 1000000007;
  else
    cout << (power(a, n + 1)[0][1] - 1 + 1000000007) % 1000000007;

  return 0;
}