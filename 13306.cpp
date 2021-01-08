#include <stdio.h>
#include <stack>

using namespace std;

int Find(int *root, int node)
{
  if (root[node] == -1)
    return node;
  root[node] = Find(root, root[node]);
  return root[node];
}
void Union(int *root, int nodeA, int nodeB)
{
  if (Find(root, nodeA) == Find(root, nodeB))
    return;
  else
    root[Find(root, nodeA)] = Find(root, nodeB);
  return;
}

int main(void)
{
  int N, Q;
  scanf("%d %d", &N, &Q);
  int parent[N + 1];
  parent[1] = -1;
  for (int i = 2; i <= N; ++i)
  {
    scanf("%d", parent + i);
  }
  Q += N - 1;
  int querry[Q][3];
  for (int i = 0; i < Q; ++i)
  {
    scanf("%d", &querry[i][0]);
    if (querry[i][0])
    {
      scanf("%d %d", &querry[i][1], &querry[i][2]);
    }
    else
    {
      scanf("%d", &querry[i][1]);
    }
  }
  stack<bool> result;
  int root[N + 1];
  fill(root, root + N + 1, -1);
  for (int i = Q - 1; i >= 0; --i)
  {
    if (querry[i][0])
    {
      result.push(Find(root, querry[i][1]) == Find(root, querry[i][2]));
    }
    else
    {
      Union(root, querry[i][1], parent[querry[i][1]]);
    }
  }
  while (!result.empty())
  {
    printf("%s\n", result.top() ? "YES" : "NO");
    result.pop();
  }
}