#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  stack<char> S;
  string str;
  cin >> str;

  for (int i = 0; i < str.size(); i++)
  {
    char c = str.at(i);
    if ('A' <= c && c <= 'Z')
      cout << c;
    else if (c == '(')
      S.push(c);
    else if (c == ')')
    {
      while (S.top() != '(')
      {
        cout << S.top();
        S.pop();
      }
      S.pop();
    }
    else
    {
      while (!S.empty() && precedence(S.top()) >= precedence(c))
      {
        cout << S.top();
        S.pop();
      }
      S.push(c);
    }
  }
  while (!S.empty())
  {
    cout << S.top();
    S.pop();
  }
}
int precedence(char c)
{
  if (c == '(')
    return 0;
  else if (c == '+' || c == '-')
    return 1;
  else if (c == '*' || c == '/')
    return 2;
}