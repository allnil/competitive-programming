#include "stdio.h"
#include <vector>
#include <iostream>

int main() {
  int c = 0;
  int k = 0;

  while (1) {
    std::vector<int> f(101);
    std::vector<int> v; v.reserve(2000000);

    scanf("%d", &c);

    if (c == 0) {
      break;
    }
    while (c--) {
      scanf("%d", &k);
      v.push_back(k);
      ++f[k];
    }

    bool firstEl = true;
    for(int i = 1; i < f.size()-1; i++) {
      int cnt = f[i];
      while(cnt--) {{ if (firstEl == true) { printf("%d", i); firstEl = false;} else {printf(" %d", i); }}}
    };
    printf("\n");
  }

  return 0;
}