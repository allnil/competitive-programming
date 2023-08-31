#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Ant
{
  double L;
  double W;
  double H;
};

bool compareTwoAnts(Ant a, Ant b) {
  double va = a.H * a.L * a.W;
  double vb = b.H * b.L * b.W;

  if (a.H != b.H) {
    return a.H > b.H;
  }

  return va > vb;
}

int main() {
  int n;
  vector<Ant> aa;aa.reserve(100);

  while(scanf("%d", &n)){
    aa.resize(0);
    if (n == 0){
      break;
    }
    Ant a;
    while(n--) {
      scanf("%lf %lf %lf", &a.L, &a.W, &a.H);
      aa.push_back(a);
    }
    sort(aa.begin(), aa.end(), compareTwoAnts);
    printf("%d\n", (int)(aa[0].H * aa[0].L * aa[0].W));
  }

  return 0;
}