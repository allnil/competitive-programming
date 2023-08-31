#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;


int main() {
    int n,q; scanf("%d %d", &n,&q);
    unordered_map<int, int>m;
    string str = "";
    int restart = 0;
    while (q--) {
      char tmp[10];
      int a, b; 
      scanf("%10s", tmp);
      str = tmp;
      if (str == "SET") {
        scanf("%d %d", &a, &b);
        m[a] = b;
      } else if (str == "RESTART") {
        scanf("%d", &a);
        m.clear();
        restart = a;
      } else if (str ==  "PRINT") {
        scanf("%d", &a);
        if (m.count(a) == 0) 
          printf("%d\n", restart);  
        else 
          printf("%d\n", m[a]);
      }
    }
    
    return 0;
}