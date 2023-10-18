#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int main()
{

  int N, M, L, K;

  scanf("%d %d %d %d", &N, &M, &L, &K);

  vector<pii> star;
  int solution = K;
  while (K--)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    star.push_back(make_pair(x, y));
  }
  sort(star.begin(), star.end());
  int max = 0;
  for (int i = 0; i < star.size(); ++i)
  {

    for (int l = 0; l <= L; l++)
    {
      int xMin = star[i].first - l;
      int yMin = star[i].second;
      int deffence = 0;
      int xMax = star[i].first + L - l;
      int yMax = star[i].second + L;
      for (int j = 0; j < star.size(); ++j)
      {

        int x = star[j].first;
        int y = star[j].second;
        if (x >= xMin && y >= yMin && x <= xMax && y <= yMax)
          deffence++;
      }
      max = max < deffence ? deffence : max;
    }
  }
  solution -= max;

  printf("%d", solution);
}