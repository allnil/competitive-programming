#include "stdio.h"
#include <vector>
#include <iostream>

int main() {
  int c = 0;
  int k = 0;

  while (1) {
    std::vector<int> f(99);
    std::vector<int> v; v.reserve(2000000);

    scanf("%d", &c);
    if (c == 0) {
      break;
    }
    while (c--) {
      scanf("%d", &k);
      v.push_back(k);
      ++f[k-1];
    }

    std::vector<int> out; out.resize(v.size());

    // prefix sum
    int sum_of_elems = 0;
    for (auto& n : f) {
        sum_of_elems += n;
        n = sum_of_elems;
    }

    for(std::vector<int>::size_type i = v.size() - 1; 
        i != (std::vector<int>::size_type) -1; i--) {
        int idx = f[v[i] - 1] - 1;
        out[idx] = v[i];
        f[v[i] - 1] -= 1;
    }

    for(size_t i = 0; i < out.size()-1; i++)
      printf("%d ", out[i]);
    printf("%d\n", out[out.size()-1]);
  }


  return 0;
}