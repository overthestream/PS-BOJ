#include <iostream>
#include <cstring>

#define endl "\n"
#define MAX 1010
using namespace std;

struct COORD
{
  int x;
  int y;
};

int N, W;
int DP[MAX][MAX];
COORD Event[MAX];

int Max(int A, int B) { return A > B ? A : B; }
int Min(int A, int B) { return A < B ? A : B; }

void Input()
{
  cin >> N >> W;
  for (int i = 1; i <= W; i++)
  {
    cin >> Event[i].x >> Event[i].y;
  }
}

int Find_Dist(int x, int y, int xx, int yy) { return abs(xx - x) + abs(yy - y); }

int Total_Distance(int Police1, int Police2)
{
  if (Police1 == W || Police2 == W)
    return 0;
  if (DP[Police1][Police2] != -1)
    return DP[Police1][Police2];

  int Next_Event = Max(Police1, Police2) + 1;
  int Dist1, Dist2;

  if (Police1 == 0)
    Dist1 = Find_Dist(1, 1, Event[Next_Event].x, Event[Next_Event].y);
  else
    Dist1 = Find_Dist(Event[Police1].x, Event[Police1].y, Event[Next_Event].x, Event[Next_Event].y);

  if (Police2 == 0)
    Dist2 = Find_Dist(N, N, Event[Next_Event].x, Event[Next_Event].y);
  else
    Dist2 = Find_Dist(Event[Police2].x, Event[Police2].y, Event[Next_Event].x, Event[Next_Event].y);

  int Result1 = Dist1 + Total_Distance(Next_Event, Police2);
  int Result2 = Dist2 + Total_Distance(Police1, Next_Event);
  DP[Police1][Police2] = Min(Result1, Result2);
  return DP[Police1][Police2];
}

void Route(int P1, int P2)
{
  if (P1 == W || P2 == W)
    return;

  int Next_Event = Max(P1, P2) + 1;
  int Dist1, Dist2;

  if (P1 == 0)
    Dist1 = Find_Dist(1, 1, Event[Next_Event].x, Event[Next_Event].y);
  else
    Dist1 = Find_Dist(Event[P1].x, Event[P1].y, Event[Next_Event].x, Event[Next_Event].y);

  if (P2 == 0)
    Dist2 = Find_Dist(N, N, Event[Next_Event].x, Event[Next_Event].y);
  else
    Dist2 = Find_Dist(Event[P2].x, Event[P2].y, Event[Next_Event].x, Event[Next_Event].y);

  if (DP[Next_Event][P2] + Dist1 < DP[P1][Next_Event] + Dist2)
  {
    cout << 1 << endl;
    Route(Next_Event, P2);
  }
  else
  {
    cout << 2 << endl;
    Route(P1, Next_Event);
  }
}

void Solution()
{
  memset(DP, -1, sizeof(DP));
  cout << Total_Distance(0, 0) << endl;
  Route(0, 0);
}

void Solve()
{
  Input();
  Solution();
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}
