#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
  int c;

  while (scanf("%d", &c) == 1) {
    std::vector<int> v; v.reserve(3000);
    std::unordered_set <int> s ;

    bool fl = true;
    while(c--) {
      int n;scanf("%d",&n); v.push_back(n);    
    }

    if (v.size() == 1) { printf("Jolly\n"); continue;};

    for (int i = 0; i < v.size() - 1; i++) {
      int d = abs(v[i] - v[i+1]);

      if (s.count(d) || d == 0 || (d > v.size() - 1)){
        printf("Not jolly\n");
        fl = false;
        break;
      } else {
        s.insert(d);
      }
    }
    if (fl == true) {printf("Jolly\n");};
  }
  
  return 0;
}