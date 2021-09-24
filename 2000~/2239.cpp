#include <cstdio>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

stack<pii> toFill;

int rowStatus[9];
int colStatus[9];
int squareStatus[9];

int sudoku[9][9];

int kthSquare(int, int);
void solve();
void DFS();
bool statusCheck(int, int, int);

int main()
{
  stack<pii> tmp;
  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
    {
      scanf("%1d", &sudoku[i][j]);
      int num = sudoku[i][j];
      if (num)
      {
        rowStatus[j] |= 1 << num;
        colStatus[i] |= 1 << num;
        squareStatus[kthSquare(i, j)] |= 1 << num;
      }
      else
      {
        tmp.push(make_pair(i, j));
      }
    }
  while (!tmp.empty())
  {
    toFill.push(tmp.top());
    tmp.pop();
  }
  solve();
}

int kthSquare(int i, int j)
{

  int row, col;

  if (j < 3)
    row = 0;
  else if (j < 6)
    row = 3;
  else
    row = 6;

  if (i < 3)
    col = 0;
  else if (i < 6)
    col = 1;
  else
    col = 2;

  return row + col;
}

void solve()
{
  DFS();
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
      printf("%d", sudoku[i][j]);
    if (i != 8)
      printf("\n");
  }
}

void DFS()
{
  if (toFill.empty())
    return;
  pii cur = toFill.top();
  toFill.pop();

  int i = cur.first;
  int j = cur.second;
  for (int k = 1; k < 10; ++k)
  {
    if (statusCheck(i, j, k))
    {
      rowStatus[j] |= 1 << k;
      colStatus[i] |= 1 << k;
      squareStatus[kthSquare(i, j)] |= 1 << k;
      sudoku[i][j] = k;
      DFS();
      if (toFill.empty())
        return;
      rowStatus[j] &= ~(1 << k);
      colStatus[i] &= ~(1 << k);
      squareStatus[kthSquare(i, j)] &= ~(1 << k);
    }
  }
  toFill.push(cur);
}
bool statusCheck(int i, int j, int k)
{
  if (rowStatus[j] & 1 << k)
    return false;
  if (colStatus[i] & 1 << k)
    return false;
  if (squareStatus[kthSquare(i, j)] & 1 << k)
    return false;

  return true;
}