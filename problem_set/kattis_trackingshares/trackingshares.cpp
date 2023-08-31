#include <stdio.h>
#include <string>
#include <map>

using namespace std;


int main() {
    int c; scanf("%d", &c);
    int prev = 0;
    int k = 0;
    map<int, int> m;
    map<int, int>days;

    while (c--) {
      scanf("%d", &k);

      prev = 0;
      while (k--)
      {
        int n,d; scanf("%d %d", &n, &d);
        map<int, int>::iterator it = days.find(d); 
        if (it != days.end())
          it->second += n;
        else 
          days[d] = n;     
      };

      printf("hi\n");
      for (auto it = days.begin(); it != days.end(); ++it) {
          int cur = it->second;
          cur = cur - prev;

          prev = it->second;
  
          map<int, int>::iterator it1 = m.find(it->first); 
          if (it1 != m.end())
            m[it->first] += cur;
          else 
            m[it->first] = cur;
      };
      m.clear();
    };

    string out;
    
    int acumulated = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
      out += (to_string(acumulated += it->second));
     if (std::next(it) != m.end()) {
      out += " ";
     }
    }

    printf("%s\n", out.c_str());
    return 0;
}