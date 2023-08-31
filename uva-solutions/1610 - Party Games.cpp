#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
  int n = 0;

  char c[50];
  vector<string> ss; ss.reserve(1000);

  while(scanf("%d", &n)) {
    if(n == 0) {
      break;
    }
    while(n--){
      scanf("%30s", 35);
      string s = c;
      ss.push_back(s);
    }

  }

  return 0;
}
