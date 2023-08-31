#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  vector<int> n;
  n.reserve(10000);

  int num; 
  while(scanf("%d", &num) != EOF) {
    n.push_back(num);
    nth_element(n.begin(), 
                n.begin() + n.size() / 2, 
                n.end());

    int m1 = *(n.begin() + n.size() / 2);
    int m2 = m1;

    if (n.size() % 2 == 0)
    {
        nth_element(n.begin(), 
                    n.begin() + n.size() / 2 - 1, 
                    n.end());
        m2 = *(n.begin() + n.size() / 2 - 1);
    }
    printf("%d\n", (m1 + m2)/2);
  }
  
  return 0;
}