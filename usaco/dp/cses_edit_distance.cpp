#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int main(){
  std::string n, m; std::cin >> n >> m;

  std::vector<std::vector<int> > dp(n.size() + 1, std::vector<int>(m.size() + 1, 0));
  

  for(int i = 0; i <= n.size(); i++){
    for(int j = 0; j <= m.size(); j++){
      if(i == 0){
        dp[i][j] = j;
        continue;
      }
      if(j == 0){
        dp[i][j] = i;
        continue;
      }
      
      dp[i][j] = dp[i-1][j - 1];
      if(n[i-1] != m[j-1]){ 
        dp[i][j] = min({dp[i][j] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1});
      }
    } 
  }



  std::cout << dp[n.size()][m.size()] << endl;
  return 0;
}

