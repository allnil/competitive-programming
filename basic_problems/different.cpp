#include "stdio.h"
#include "cstdlib"

int main() {
  long long a, b= 0;

  while (scanf("%lld %lld", &a, &b) != EOF) {
    printf("%lld\n", llabs(a - b));
  }
  return 0;
}