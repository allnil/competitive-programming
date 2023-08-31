#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map< string, int > chainLengths;
int maxVal = 1;

int main() {
  int n; scanf("%d", &n);
  char r1[30], r2[30], act[30];
  chainLengths["polycarp"] = 1;
  while(n--){
    scanf("%s reposted %s", r1, r2);
    string a = r1;
    string b = r2;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    chainLengths[a] = chainLengths[b] + 1;
    if (chainLengths[a] > maxVal) {
      maxVal = chainLengths[a];
    }
  }
  
  printf("%d\n", maxVal);
  return 0;
}