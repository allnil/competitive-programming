#include "stdio.h"
#include <cstdio>
#include <vector>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  vector<int> dp(3);

  for(int day = 0; day < n; ++day){
    vector<int> new_dp(3, 0);
    vector<int> c(3);
    for(int i = 0; i < 3; ++i) {
      scanf("%d", &c[i]);
    }

    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j){
        if(i != j) {
          new_dp[j] = max(new_dp[j], dp[i] + c[j]);
        }
      }
    }
    dp = new_dp;
  }
  printf("%d\n", max({dp[0], dp[1], dp[2]}));
  return 0;
}
