#include "stdio.h"

int main() {
  double c, q, y = 0;

  scanf("%lf", &c);
  double accum = 0;
  while (c--) {
    scanf("%lf %lf", &q, &y);
    accum += q*y;
  }
  printf("%.3lf\n", accum);
  return 0;
}