#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t; scanf("%d", &t);
  int format = t;
  while(t--) {
    vector< vector<int> > r; r.resize(3);

    for(int i = 0; i < 3; i++) {
      int n;scanf("%d", &n);
      r[i].reserve(n);
      while(n--) {
        int p;scanf("%d", &p);
        r[i].push_back(p);
      }
      sort(r[i].begin(), r[i].end()); 
    }
/*
    for (auto needle : needles) {
        std::cout << "Searching for " << needle << '\n';
        if (std::binary_search(haystack.begin(), haystack.end(), needle)) {
            std::cout << "Found " << needle << '\n';
        } else {
            std::cout << "no dice!\n";
        }
    }
*/  

    vector<int> r1;
    int a = 0;
    for (auto problem : r[0]) {
        if (!std::binary_search(r[1].begin(), r[1].end(), problem)) {
          if (!std::binary_search(r[2].begin(), r[2].end(), problem)) {
              r1.push_back(problem);
              a++;
          };
        };
    }

    vector<int> r2;
    int b = 0;
    for (auto problem : r[1]) {
        if (!std::binary_search(r[0].begin(), r[0].end(), problem)) {
          if (!std::binary_search(r[2].begin(), r[2].end(), problem)) {
              r2.push_back(problem);
              b++;
          };
        };
    }

    vector<int> r3;
    int c = 0;
    for (auto problem : r[2]) {
        if (!std::binary_search(r[0].begin(), r[0].end(), problem)) {
          if (!std::binary_search(r[1].begin(), r[1].end(), problem)) {
              r3.push_back(problem);
              c++;
          };
        };
    }

    printf("Case #%d:\n", format-t);
    if(a>=b && a>=c) {
      printf("1 %d", a);
      for(int x: r1) // for integer x in vector A
        printf(" %d", x); 
      printf("\n");
    }

    if(b>=a && b>=c){
      printf("2 %d", b);
      for(int x: r2) // for integer x in vector A
        printf(" %d", x); 
      printf("\n");
    }

    if(c>=b && c>=a) {
      printf("3 %d", c);
      for(int x: r3) // for integer x in vector A
        printf(" %d", x); 
      printf("\n");
    }
  }
  return 0;
}